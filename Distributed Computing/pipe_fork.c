#include <stdio.h> 
#include<stdlib.h>
#include <unistd.h> 
#define MSGSIZE 16 
char* msg1 = "hello, world #1"; 
char* msg2 = "hello, world #2"; 
char* msg3 = "hello, world #3"; 
  
int main() 
{ 
    char inbuf[MSGSIZE]; 
    int p[2], pid, nbytes; 
  

    //printf("c1\n");
    if (pipe(p) < 0) 
        exit(1); 
  
    pid = fork();
    printf("%d\n",pid);
    /* continued */
    //printf("c2\n");
    if (pid > 0) { 
        //printf("msg called\n");
        write(p[1], msg1, MSGSIZE); 
        //printf("msg called\n");
        write(p[1], msg2, MSGSIZE); 
        //printf("msg called\n");
        write(p[1], msg3, MSGSIZE);  

        close(p[1]);
        int cpid = wait(NULL);
        printf("%d\n",cpid);
    } 
  
    else if(pid==0){  

        close(p[1]);
        nbytes = read(p[0],inbuf,MSGSIZE);
        while (nbytes > 0) 
        {   
            printf("%d\n",nbytes);
            printf("Buffer content print entered\n");
            printf("%s\n", inbuf); 

            nbytes = read(p[0],inbuf,MSGSIZE);
            //if(nbytes==0)return 0;

        }
        

        // if (nbytes != 0)
        // {
        //     printf("Child entry\n");
        //     exit(2);

        // } 
             
        printf("Finished reading\n");
        
    } 
    printf("c3\n");

    return 0; 
} 