#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 


int main() 
{ 
  
    // make two process which run same 
    // program after this instruction 
    int x = 1;
    int ret = fork();

    //positive value - parent process 
    //zero value - child process
  	

  	pid_t pid = getpid();

  	printf("pid: %lun \n", pid);


  	if(ret==0)
  	{
  		printf("child process\n");
    	printf("Hello world!\n");
    	printf("%d\n",++x);	
  	}

  	else 
  	{
  		printf("process id of created child process is %d\n",ret);
  		printf("parent process\n");
    	printf("Hello world!\n");
    	printf("%d\n",--x);
  	 
     
  	}

  	return 0;
} 