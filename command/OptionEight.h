//
// Created by mor on 1/13/23.
//

#ifndef KNN_CLASSIFICATION_SERVER_OPTIONEIGHT_H
#define KNN_CLASSIFICATION_SERVER_OPTIONEIGHT_H

#include "Command.h"
#include "KNN.h"

class OptionEight : public Command{
private:
    KNN knn;
public:
    OptionEight();
    OptionEight(DefaultIO *dio,KNN &knn);
    void execute() override;
};

#endif //KNN_CLASSIFICATION_SERVER_OPTIONEIGHT_H
