//
// Created by mor on 1/13/23.
//
#ifndef KNN_CLASSIFICATION_SERVER_OPTIONONE_H
#define KNN_CLASSIFICATION_SERVER_OPTIONONE_H
#include "Command.h"
#include "../utilities/Operations.h"


class OptionTwo : public Command{
private:
    KNN knn;

public:
    OptionTwo();
    OptionTwo(DefaultIO &io,KNN &knn);
    //void printDescription();
    void execute() override;

};
#endif //KNN_CLASSIFICATION_SERVER_OPTIONTWO_H
