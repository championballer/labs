#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <iostream>
using namespace std;

class file_obj
{
	public:
	bool waiting[3];
	bool lock;
};

int main()
{
	// ftok to generate unique key for ipc
    key_t key = ftok("shmfile",65);
 
    // shmget returns an identifier in shmid
    int shmid = shmget(key,1024,0666|IPC_CREAT);
 
    // shmat to attach to shared memory
    file_obj *obj = (file_obj*) shmat(shmid,(void*)0,0);
	for(int i=0;i<3;i++)
		obj->waiting[i]=false;
	obj->lock=false;
	shmdt(obj);    
}
