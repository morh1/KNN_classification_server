#ifndef KNN_CLASSIFICATION_SERVER_COMMAND_H
#define KNN_CLASSIFICATION_SERVER_COMMAND_H


#include <string>
#include "Command.h"
#include "DefaultIO"
using namespace std;
class Command {
protected:
    string description;
    DefultIO dio;
public:
    //execute() abstract method
    virtual void execute() = 0;

    //printDescription() abstract method
    virtual void printDescription() = 0;
};


#endif //KNN_CLASSIFICATION_SERVER_COMMAND_H
