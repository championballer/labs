#include <stdio.h> 
#include <unistd.h> 
#define MSGSIZE 32
char* msg1 = "This is Shiv Kumar Chandok"; 
char* msg2 = "I am ready to fight as long as it takes"; 
char* msg3 = "hello, world #3"; 

int main() 
{ 
    char inbuf[MSGSIZE]; 
    int p[2], i; 
  	

  	//construction of a pipe
    if (pipe(p) < 0) 
        exit(1); 
  
    /* continued */
    /* write pipe */
  
    write(p[1], msg1, MSGSIZE); 
    write(p[1], msg2, MSGSIZE); 
    write(p[1], msg3, MSGSIZE); 
  
    for (i = 0; i < 3; i++) { 
        /* read pipe */
        read(p[0], inbuf, MSGSIZE); 
        printf("% s\n", inbuf); 
    } 
    return 0; 
} 