#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;
 
class file_obj
{
    public:
    int readcount;
    int wrt;
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
 
    cout<<"Read Request"<<endl;

    wait(obj->mutex);
    obj->readcount++;
    if(obj->readcount==1)
        wait(obj->wrt);
    signal(obj->mutex);

    cout<<"In critical section"<<endl;
    usleep(5000000);
    ///TAKES 5 Sec
    cout<<"READ"<<endl;

    wait(obj->mutex);
    obj->readcount--;
    if(obj->readcount==0)
        signal(obj->wrt);
    signal(obj->mutex);

    //detach from shared memory 
    shmdt(obj);
   
    return 0;
}