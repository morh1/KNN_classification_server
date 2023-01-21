#include "client.h"
#include "../IO/SocketIO.h"

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>


using namespace std;
int creatSocket(const char* ip_address,int port){
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }
    return sock;
}

int main(int argc,char** argv){
    const char* ip_address = "127.0.0.1";
    const int port_no = atoi(argv[1]);
    int clientSock = creatSocket(ip_address,port_no);
    SocketIO dio = SocketIO(clientSock);
    string input;
    char buffer[4096];

    while (true)  {
        string str = dio.read();
        if (!str.empty())
        cout << str<<endl;
    }


    do{


        /*
 *recv(clientSock,buffer,sizeof(char),0);
        string s(buffer);

        cin >> input;
        const char* send_buffer = input.c_str();
        cout << send(clientSock,send_buffer, strlen(send_buffer),0) <<endl; */
    } while (input != "8");
}