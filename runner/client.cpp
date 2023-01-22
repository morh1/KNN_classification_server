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

#include <iostream>
#include <fstream>
#include <sstream>
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
void sendFile(string path,SocketIO sock) {
    ifstream file(path);
    stringstream buffer;
    buffer << file.rdbuf();
    string csv_string = buffer.str();
    sock.write(csv_string);
}
void inputOne(SocketIO socketIo,StandardIO standardIo){
    standardIo.write(socketIo.read());
    string path =  standardIo.read();
    sendFile(path,socketIo);
    string output = socketIo.read();
    standardIo.write(output);
    if (output == ERROR){
        return;
    }
    standardIo.write(socketIo.read());
    path =  standardIo.read();
    sendFile(path,socketIo);
    standardIo.write(socketIo.read());
}
void inputFive(SocketIO socketIo,StandardIO standardIo){
    if(socketIo.read() == "false"){
        standardIo.write(socketIo.read());
        return;
    }
    string path = standardIo.read();
    string data = socketIo.read();
    thread thread(toPath,path,data);
    thread.detach();
}
void inputTwo(SocketIO socketIo,StandardIO standardIo){
    standardIo.write(socketIo.read());
    socketIo.write(standardIo.read());
    //if k isnt valid
    if(socketIo.read()=="false"){
        standardIo.write(socketIo.read());
    }
    //if the matric isnt valid
    if(socketIo.read()=="false"){
        standardIo.write(socketIo.read());
    }
}
void inputThree(SocketIO socketIo,StandardIO standardIo){
    standardIo.write(socketIo.read());
}
void inputFour(SocketIO socketIo,StandardIO standardIo){
    standardIo.write(socketIo.read());
}
void inputEight(SocketIO socketIo,StandardIO standardIo){
    return;
}
bool routeInput(SocketIO socketIo,StandardIO standardIo,string input){
    if(input=="1"){
        inputOne( socketIo, standardIo);
        return true;
    }
    if(input=="2"){
        inputTwo( socketIo, standardIo);
        return true;
    }
    if(input=="3"){
        inputThree( socketIo, standardIo);
        return true;
    }
   if(input=="5"){
        inputFive( socketIo, standardIo);
        return true;
    }
   if(input=="8"){
        inputEight( socketIo, standardIo);
        return true;
   }

    return false;

}

int main(int argc,char** argv){
    const char* ip_address = "127.0.0.1";
    const int port_no = atoi(argv[1]);
    int clientSock = creatSocket(ip_address,port_no);
    SocketIO socketIo = SocketIO(clientSock);
    StandardIO standardIo = StandardIO();
    string input,output,path,data;
    char buffer[4096];
    while (true){
        cout << "back for another loop "<<endl;
        //write the option list on the client screen.
        standardIo.write(socketIo.read());
        //read the input of the user(shoulde be a number)
        input=standardIo.read();
        //sand to the server
        socketIo.write(input);
        if(!routeInput(socketIo,standardIo,input)){
            //we will get an error massage
            standardIo.write(socketIo.read());
        }
        /*
        if (input == "1"){
            standardIo.write(socketIo.read());
            path =  standardIo.read();
            sendFile(path,socketIo);
            output = socketIo.read();
            standardIo.write(output);
            if (output == ERROR){
                continue;
            }
            standardIo.write(socketIo.read());
            path =  standardIo.read();
            sendFile(path,socketIo);
            standardIo.write(socketIo.read());
        }
        if(input=="5"){
            path = standardIo.read();
            data = socketIo.read();
            thread thread(toPath,path,data);
            thread.detach();
        }
        if(input=="8"){
            socketIo.write(input);
            return 0;
        }*/
    }
}
