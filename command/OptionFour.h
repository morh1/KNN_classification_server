//
// Created by mor on 1/13/23.
//

#ifndef KNN_CLASSIFICATION_SERVER_OPTIONONE_H
#define KNN_CLASSIFICATION_SERVER_OPTIONONE_H
#include "Command.h"
#include "../utilities/Operations.h"
class OptionFour : public Command{
private:
    KNN knn;
public:
    OptionFour();
    OptionFour(DefaultIO &io,KNN &knn);
    void execute() override;

    void printDescription();
};
#endif //KNN_CLASSIFICATION_SERVER_OPTIONFOUR_H
