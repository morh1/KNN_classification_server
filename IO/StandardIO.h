#ifndef KNN_CLASSIFICATION_SERVER_STANDARDIO_H
#define KNN_CLASSIFICATION_SERVER_STANDARDIO_H


#include "DefaultIO.h"
#include <cstdio>
#include <iostream>
using namespace std;
class StandardIO : public DefaultIO {
    string read();

    void write(string string);
};


#endif //KNN_CLASSIFICATION_SERVER_STANDARDIO_H
