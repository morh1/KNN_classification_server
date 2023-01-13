//
// Created by yarin on 1/13/23.
//
#include <string>
#include "Command.h"
#include "DefaultIO"
using namespace std;
class Command{
protected:
    string description;
    DefultIO dio;
public:
    //execute() abstract method
    virtual void execute() = 0;
    //printDescription() abstract method
    virtual void printDescription() = 0;

};
