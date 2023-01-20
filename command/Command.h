#ifndef KNN_CLASSIFICATION_SERVER_COMMAND_H
#define KNN_CLASSIFICATION_SERVER_COMMAND_H


#include <string>
#include "../IO/DefaultIO.h"


#define UPLOAD_CSV_TRAIN "Please upload your local train CSV file."
#define UPLOAD_CSV_TEST "Please upload your local test CSV file."
#define ERROR "ERROR"
#define ERROR_MET "invalid value for metric"
#define ERROR_K "invalid value for K"
#define PS_UPLOAD "please upload data"
#define COMPLETE "classifying data complete"
#define CLASSIFY "please classify the data"


using namespace std;
class Command {
protected:
    string description;
    DefaultIO *dio;
public:
    Command();

    //execute() abstract method
    virtual void execute() =0;

    //printDescription() abstract method
    void printDescription();
};


#endif //KNN_CLASSIFICATION_SERVER_COMMAND_H
