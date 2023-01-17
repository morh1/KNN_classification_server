//
// Created by mor on 1/13/23.
//
#ifndef KNN_CLASSIFICATION_SERVER_OPTIONONE_H
#define KNN_CLASSIFICATION_SERVER_OPTIONONE_H
#include "Command.h"
#include "../utilities/Operations.h"
class OptionThree : public Command{
private:
    KNN knn;
public:
    OptionThree();
    OptionThree(DefaultIO &io,KNN &knn);
    void execute() override;
    void printDescription();
};

#endif //KNN_CLASSIFICATION_SERVER_OPTIONTHREE_H
