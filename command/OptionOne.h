//
// Created by mor on 1/13/23.
//

#ifndef KNN_CLASSIFICATION_SERVER_OPTIONONE_H
#define KNN_CLASSIFICATION_SERVER_OPTIONONE_H

#include "Command.h"
#include "../utilities/Operations.h"
class OptionOne : public Command{
private:
    KNN *knn;
    DefaultIO *io;

public:
    OptionOne();
    OptionOne(DefaultIO *io,KNN* knn);
    //void printDescription();
    void execute() override;
};


#endif //KNN_CLASSIFICATION_SERVER_OPTIONONE_H
