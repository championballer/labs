#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <iostream>
using namespace std;

class file_obj
{
	public:
	int buffer[5];
	int full;
	int empty;
	int mutex;
	int item;
	int in,out;
};
void wait(int &S)
{
	while(S<=0);
	S--;
}
void signal(int &S)
{
	S++;
}
int main()
{
	// ftok to generate unique key
    key_t key = ftok("shmfile",65);
 
    // shmget returns an identifier in shmid
    int shmid = shmget(key,1024,0666|IPC_CREAT);
 
    // shmat to attach to shared memory
    file_obj *obj = (file_obj*) shmat(shmid,(void*)0,0);

    cout<<"Consumer Request"<<endl;
    wait(obj->full);
    wait(obj->mutex);

    cout<<"In critical section"<<endl;
    usleep(2000000);
    int nextc=obj->buffer[obj->out];
    obj->out=(obj->out+1)%5;

    cout<<"Item Consumed "<<nextc<<endl;

    signal(obj->mutex);
    signal(obj->empty);

    shmdt(obj);
}