//
// Created by mor on 1/13/23.
//

#ifndef KNN_CLASSIFICATION_SERVER_OPTIONTWO_H
#define KNN_CLASSIFICATION_SERVER_OPTIONTWO_H


#include "../IO/DefaultIO.h"
#include "../utilities/KNN.h"
#include "../utilities/Utilities.h"
#include "Command.h"

class OptionTwo : public Command{
private:
    KNN* knn;
public:
    OptionTwo();
    OptionTwo(DefaultIO *dio,KNN* knn);
    void execute() override ;

};

#endif //KNN_CLASSIFICATION_SERVER_OPTIONTWO_H
