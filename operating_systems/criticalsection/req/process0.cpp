#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <iostream>
using namespace std;

class file_obj
{
	public:
	bool mark[2];
};
int main()
{
	// ftok to generate unique key
    key_t key = ftok("shmfile",65);
 
    // shmget returns an identifier in shmid
    int shmid = shmget(key,1024,0666|IPC_CREAT);
 
    // shmat to attach to shared memory
    file_obj *obj = (file_obj*) shmat(shmid,(void*)0,0);
    int i=0,j=1;

    cout<<"Request by "<<i<<endl;
    obj->mark[i]=true;
    while(obj->mark[j]);

    cout<<"Critical section "<<i<<endl;
    usleep(5000000);

   	obj->mark[i]=false;

	shmdt(obj);    
}