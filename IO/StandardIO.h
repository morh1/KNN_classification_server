#ifndef KNN_CLASSIFICATION_SERVER_STANDARDIO_H
#define KNN_CLASSIFICATION_SERVER_STANDARDIO_H


#include "DefaultIO.h"
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>
using namespace std;
/**
 * this class stands for IO via the command line.
 */
class StandardIO : public DefaultIO {
public:
    /**
     * this function reads from the command line.
     * @return
     */
    string read();
    /**
     * this function reads from the command line.
     * @return
     */
    void write(string string);
};


#endif //KNN_CLASSIFICATION_SERVER_STANDARDIO_H
