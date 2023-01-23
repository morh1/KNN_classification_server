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
/**
 * this class stands for the IO via socket.
 */
class SocketIO : public DefaultIO{
    int sock;
public:
    /**
     * SocketIO constructor init by a sock number.
     */
    SocketIO(int client_sock);
    /**
     * the read function of SocketIO ,read the string from the buffer ,for be able to get strings larger the
     * some constant ,we using symbol "@" that stands for the end of the read value.
     * @return
     */
    string read();
    /**
     * The write function of Socket IO is write data based on the connected socket, the @ is using in the read
     * function to recognize when the string is over.
     * @param string
     */
    void write(string string);
    /**
     * this function closes the socket of the SocketIO object.
     */
    void closeSocket();
};


#endif //KNN_CLASSIFICATION_SERVER_SOCKETIO_H















