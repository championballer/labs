#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <iostream>
using namespace std;

class file_obj
{
	public:
	int item[3];
	int mutex;
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

    cout<<obj->mutex<<" ";
    wait(obj->mutex);
    int c;
    cout<<"Choice: ";
    cin>>c;
    if(c==1)
    {
        signal(obj->item[0]);
        signal(obj->item[1]);
    }
    else if(c==2)
    {
        signal(obj->item[1]);
        signal(obj->item[2]);
    }
    else 
    {
        signal(obj->item[0]);
        signal(obj->item[2]);
    }
    signal(obj->mutex);
    
	shmdt(obj);    
}