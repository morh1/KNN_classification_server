#include "client.h"
#include "SocketIO.h"

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>


using namespace std;
int creatSocket(const char* ip_address,int port){
    int sock = socket(AF_INET, SOCK_STREAM,0);
    if (sock < 0){
        perror("error creating socket");
        return 0;
    }
    struct sockaddr_in sin;
    memset(&sin,0, sizeof(sin));
    sin.sin_family= AF_INET;
    sin.sin_addr.s_addr= inet_addr(ip_address);
    sin.sin_port= htons(port);
    if (connect(sock,(struct sockaddr*)&sin, sizeof(sin))<0){
        perror("error connecting to server");
        return 0;
    }
    return sock;
}

int main(){
    const char* ip_address = "127.0.0.1";
    const int port_no = 5555;
    int clientSock = creatSocket(ip_address,port_no);
    SocketIO dio;


}