#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <iostream>
using namespace std;

class file_obj
{
	public:
	bool barber;
	bool chairs[100];
	int N;
};
int main()
{
	// ftok to generate unique key
    key_t key = ftok("shmfile",65);
 
    // shmget returns an identifier in shmid
    int shmid = shmget(key,1024,0666|IPC_CREAT);
 
    // shmat to attach to shared memory
    file_obj *obj = (file_obj*) shmat(shmid,(void*)0,0);
	
	obj->N=3;
	for(int i=0;i<3;i++)
		obj->chairs[i]=false;
	obj->barber=false;
	shmdt(obj);    
}