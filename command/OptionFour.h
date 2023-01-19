#ifndef KNN_CLASSIFICATION_SERVER_OPTIONFOUR_H
#define KNN_CLASSIFICATION_SERVER_OPTIONFOUR_H

#include "Command.h"
#include "KNN.h"
class OptionFour : public Command{
private:
    KNN* knn;
public:
    OptionFour();
    OptionFour(DefaultIO *dio,KNN* knn);
    void execute() override;
};
#endif //KNN_CLASSIFICATION_SERVER_OPTIONFOUR_H
