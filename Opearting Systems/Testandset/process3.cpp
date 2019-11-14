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
bool Test_and_Set(bool &target)
{
	bool test_and_set=target;
	target=true;
	return test_and_set;
}
void swap(bool &a,bool &b)
{
	bool temp=a;
	a=b;
	b=temp;
}
int main()
{
	// ftok to generate unique key
    key_t key = ftok("shmfile",65);
 
    // shmget returns an identifier in shmid
    int shmid = shmget(key,1024,0666|IPC_CREAT);
 
    // shmat to attach to shared memory
    file_obj *obj = (file_obj*) shmat(shmid,(void*)0,0);
	int pi=2;
	cout<<"Request by "<<pi<<endl;
	bool key_s;

	obj->waiting[pi]=true;
	key_s=true;
	while(key_s && obj->waiting[pi])
	{
		key_s=Test_and_Set(obj->lock);
		///OR swap(key_s,obj->lock)
	}
	obj->waiting[pi]=false;

	cout<<"Critical Section of "<<pi<<endl;
	usleep(5000000);

	int j=(pi+1)%3;
	while(j!=pi && !obj->waiting[j])
		j=(j+1)%3;
	if(j==pi)
		obj->lock=false;
	else
		obj->waiting[j]=false;

	shmdt(obj);    
}