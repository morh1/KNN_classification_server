//
// Created by mor on 1/13/23.
//

#ifndef KNN_CLASSIFICATION_SERVER_OPTIONONE_H
#define KNN_CLASSIFICATION_SERVER_OPTIONONE_H

#include "Command.h"
#include "../utilities/Operations.h"
class OptionOne : public Command{
private:
    Operations *operation;

public:
    OptionOne(Operations *operation);
    void execute();
};


#endif //KNN_CLASSIFICATION_SERVER_OPTIONONE_H
