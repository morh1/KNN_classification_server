//
// Created by yarin on 1/18/23.
//

#ifndef KNN_CLASSIFICATION_SERVER_SOCKETIO_H
#define KNN_CLASSIFICATION_SERVER_SOCKETIO_H

#include "DefaultIO.h"

class SocketIO : public DefaultIO{
    string read();
    void write(string string);
};


#endif //KNN_CLASSIFICATION_SERVER_SOCKETIO_H















