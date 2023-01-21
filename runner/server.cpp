#include "server.h"
using namespace std;

int creatSocket(int port){
    int sock = socket(AF_INET, SOCK_STREAM,0);
    if (sock < 0){
        perror("error creating socket");
        return 0;
    }
    struct sockaddr_in sin;
    memset(&sin,0, sizeof(sin));
    sin.sin_family= AF_INET;
    sin.sin_addr.s_addr= INADDR_ANY;
    sin.sin_port= htons(port);
    if (bind(sock,(struct sockaddr*)&sin, sizeof(sin))<0){
        perror("error binding socket");
        return 0;
    }
    if (listen(sock,5) < 0){
        perror("error listening to a socket");
        return 0;
    }
    return sock;
}
/*


int acceptClient(int sock){
    struct sockaddr_in client_sin;
    unsigned int addr_len= sizeof(client_sin);
    int client_sock= accept(sock,(struct sockaddr*)&client_sin,&addr_len);
    if (client_sock<0){
        perror("error accepting client");
        return 0;
    }
    return client_sock;
}
*/
void startClient(SocketIO dio){
    CLI cli  = CLI(&dio);
    cli.start();
}
int main(){



    int server_port = 55550;
    int server_socket = creatSocket(server_port);
    if (!server_socket) return 0;
    //list<int> clients;
    vector<thread> clientThreads;
    string str = "message";

    struct sockaddr_in client_sin;
    unsigned int addr_len= sizeof(client_sin);
    char buffer[4096];
    while (true){
        int clientSock= accept(server_socket,(struct sockaddr*)&client_sin,&addr_len);
        cout << "client connected!" <<endl;
        //send(clientSock,str.c_str(),sizeof (string),0);
        if (clientSock == 0){
            perror("error accept client");
            continue;
        }
        /*

        string st = "fddsfffsd\0";
        strcpy(buffer,st.c_str());
        send(clientSock,buffer,sizeof (buffer),0);*/
        SocketIO dio = SocketIO(clientSock);
        thread thread(startClient,dio);
        thread.detach();
        clientThreads.push_back(std::move(thread));
        //startClient(clientSock);
        //clientThreads.emplace_back(startClient, clientSock);

    }

}
