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

bool Test_and_Set(bool &target)
{
	bool test_and_set=target;
	target=true;
	return test_and_set;
}
int main()
{
	// ftok to generate unique key
    key_t key = ftok("shmfile",65);
 
    // shmget returns an identifier in shmid
    int shmid = shmget(key,1024,0666|IPC_CREAT);
 
    // shmat to attach to shared memory
    file_obj *obj = (file_obj*) shmat(shmid,(void*)0,0);
	int N=obj->N,c;
	cout<<"CUSTOMER CAME"<<endl;
	bool key_s=false;
	for(int j=0;j<N;j++)
		if(!obj->chairs[j])
		{	
			obj->chairs[j]=true;
			c=j;
			key_s=true;
			break;
		}
	if(!key_s)
	{
		cout<<"CUSTOMER GOES"<<endl;
		return 0;
	}
	cout<<"CUSTOMER WAITING"<<endl;
	while(obj->chairs[c] && key_s)
		key_s=Test_and_Set(obj->barber);
	obj->chairs[c]=false;
	
	cout<<"BARBER WORKING"<<endl;
	usleep(10000000);

	key=false;
	for(int j=0;j<N;j++)
		if(obj->chairs[j])
		{
			obj->chairs[j]=false;
			key=true;
			break;
		}
	if(!key)
	{
		obj->barber=false;
		cout<<"BARBER WENT TO SLEEP"<<endl;
	}

	shmdt(obj);    
}