#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <iostream>
using namespace std;

class file_obj
{
	public:
	int number[3];
	bool choosing[3];
};
int main()
{
	// ftok to generate unique key
    key_t key = ftok("shmfile",65);
 
    // shmget returns an identifier in shmid
    int shmid = shmget(key,1024,0666|IPC_CREAT);
 
    // shmat to attach to shared memory
    file_obj *obj = (file_obj*) shmat(shmid,(void*)0,0);
    int i=0;
    cout<<"Request by "<<i<<endl;

    obj->choosing[i]=true;
    for(int j=0;j<3;j++)
    	obj->number[i]=max(obj->number[j]+1,obj->number[i]);
    obj->choosing[i]=false;

    for(int j=0;j<3;j++)
    {
    	while(obj->choosing[j]);
    	while(obj->number[j]!=0 && (obj->number[j]<obj->number[i] || (obj->number[j]==obj->number[i] && j<i)));
    }

    cout<<"Critical Section "<<i<<endl;
    usleep(5000000);

    obj->number[i]=0;

	shmdt(obj);    
}