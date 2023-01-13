#ifndef KNN_CLASSIFICATION_SERVER_COMMAND_H
#define KNN_CLASSIFICATION_SERVER_COMMAND_H


#include <string>
#include "Command.h"
#include "../IO/DefaultIO.h"


#define UPLOAD_CSV_TRAIN "Please upload your local train CSV file."
#define UPLOAD_CSV_TEST "Please upload your local test CSV file."
#define ERROR "ERROR"


using namespace std;
class Command {
protected:
    string description;
    DefaultIO *dio;
public:
    Command(DefaultIO * dio);

    Command();

    //execute() abstract method
    virtual void execute() = 0;

    //printDescription() abstract method
    virtual void printDescription() = 0;
};


#endif //KNN_CLASSIFICATION_SERVER_COMMAND_H
