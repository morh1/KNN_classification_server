#ifndef KNN_CLASSIFICATION_SERVER_SOCKETIO_H
#define KNN_CLASSIFICATION_SERVER_SOCKETIO_H

#include "DefaultIO.h"
#include <iostream>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

using namespace std;
class SocketIO : public DefaultIO{
    int sock;
public:
    string read();
    void write(string string);
    SocketIO(int client_sock);
    void closeSocket();
};


#endif //KNN_CLASSIFICATION_SERVER_SOCKETIO_H















