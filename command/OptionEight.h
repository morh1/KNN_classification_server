#ifndef KNN_CLASSIFICATION_SERVER_OPTIONEIGHT_H
#define KNN_CLASSIFICATION_SERVER_OPTIONEIGHT_H

#include "Command.h"
#include "../utilities/KNN.h"

class OptionEight : public Command{
private:
    KNN* knn;
public:
    OptionEight();
/**
 * the OptionEight constructor
 * @param (DefaultIO *dio,KNN* knn)
 */
    OptionEight(DefaultIO *dio,KNN* knn);
    void execute() override;
};

#endif //KNN_CLASSIFICATION_SERVER_OPTIONEIGHT_H
