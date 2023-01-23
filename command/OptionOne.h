//
// Created by mor on 1/13/23.
//

#ifndef KNN_CLASSIFICATION_SERVER_OPTIONONE_H
#define KNN_CLASSIFICATION_SERVER_OPTIONONE_H

#include "Command.h"
#include "../utilities/KNN.h"
#include "../utilities/Utilities.h"
class OptionOne : public Command{
private:
    KNN* knn;
public:
/**
 *  default constructor
 */
    OptionOne();
/**
 *  optionOne constructor initial the parameters
 * @param (DefaultIO * dio,KNN* knn)
 */
    OptionOne(DefaultIO *dio,KNN* knn);
/**
 *  execute option one received the vectors train and test files
 */
    void execute() override;
};


#endif //KNN_CLASSIFICATION_SERVER_OPTIONONE_H
