#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
 
int main (void)
{
    int fd[2];
    char buf1[13] = "hello world\n";
    char buf2[12];
 
    // assume foobar.txt is already created
    fd[0] = open("trial.txt", O_RDWR);        
    fd[1] = open("trial.txt", O_RDWR);
     
    write(fd[0], buf1, strlen(buf1));         
    write(1, buf2, read(fd[1], buf2, 12));
 
    close(fd[0]);
    close(fd[1]);
 
    return 0;
}
