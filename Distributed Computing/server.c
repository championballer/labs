#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <time.h> 
#define PORT 8080

int main() 
{ 

    //socket file descriptor
    int server_fd;
    int new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    //char buffer[1024] = {0}; 
       

    /*
    AF_INET : Address family for IPv4, use AF_INET6 for IPv6
    SOCK_STREAM : TCP connection
    Protocal value : 0, IPv4 (This is the same number which appears on protocol field in the IP header of a packet)
    */   
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        //if socket creation fails, then the program exits
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 

    address.sin_family = AF_INET; 

    //used to bind the ip address for the local host
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    /* 
    After creation of the socket, bind function binds the socket to the address and port number specified in addr(custom data structure). In the example code, we bind the server to the localhost, hence we use INADDR_ANY to specify the IP address.
    */ 
    if (bind(server_fd, (struct sockaddr *)&address,sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 

    /*
    It puts the server socket in a passive mode, where it waits for the client to approach the server to make a connection. The backlog, defines the maximum length to which the queue of pending connections for sockfd may grow. If a connection request arrives when the queue is full, the client may receive an error with an indication of ECONNREFUSED.
    */
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 

    /*
    It extracts the first connection request on the queue of pending connections for the listening socket, sockfd, creates a new connected socket, and returns a new file descriptor referring to that socket. At this point, connection is established between client and server, and they are ready to transfer data.
    */
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 

    time_t seconds; 
    seconds = time(NULL); 

    /* Communincation between the two sockets on the connection*/
    send(new_socket , ctime(&seconds) , 200, 0 ); 
    printf("Time message sent\n"); 
    return 0; 
} 