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
int main()
{
	// ftok to generate unique key
    key_t key = ftok("shmfile",65);
 
    // shmget returns an identifier in shmid
    int shmid = shmget(key,1024,0666|IPC_CREAT);
 
    // shmat to attach to shared memory
    file_obj *obj = (file_obj*) shmat(shmid,(void*)0,0);
	
	obj->full=0;
	obj->empty=5;
	obj->mutex=1;
	obj->item=1;
	obj->in=0;
	obj->out=0;

	shmdt(obj);    
}