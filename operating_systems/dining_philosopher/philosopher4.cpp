#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <iostream>
using namespace std;

class file_obj
{
	public:
	int chopsticks[5];
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
    int pi=4;

    cout<<"Request by P"<<pi<<endl;
    wait(obj->chopsticks[pi]);
    wait(obj->chopsticks[(pi+1)%5]);

    cout<<"Eat"<<endl;
    usleep(5000000);

    signal(obj->chopsticks[pi]);
    signal(obj->chopsticks[(pi+1)%5]);

    cout<<"Think"<<endl;

    shmdt(obj);
}
	