#include "client.h"
#include "../IO/SocketIO.h"
#include "../IO/StandardIO.h"
#include "../command/Command.h"
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <thread>


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
/**
 * The function gets the classified vectors from the csv file
 * and updates the vectors list member.
 *
 */

void toPath(string path,string data) {
    ofstream file;
    file.open(path);
    if (file.is_open()) {
        file << data;
        file.close();

    }
}

int main(int argc,char** argv){
    const char* ip_address = "127.0.0.1";
    const int port_no = atoi(argv[1]);
    int clientSock = creatSocket(ip_address,port_no);
    SocketIO socketIo = SocketIO(clientSock);
    StandardIO standardIo = StandardIO();
    string input,output;
    char buffer[4096];
    while (true){
        //read the information that sent by the server
        output=socketIo.read();
        //write it
        standardIo.write(output);
        //read the input of the user
        input=standardIo.read();
        //sand to the server
        socketIo.write(input);
        if(input=="5"){
            string path = standardIo.read();
            string data = socketIo.read();
            thread thread(toPath,path,data);
            thread.detach();

        }
        if(input=="8"){
            socketIo.write(input);
            return 0;
        }
    }
}
