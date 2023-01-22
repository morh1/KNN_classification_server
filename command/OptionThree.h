#ifndef KNN_CLASSIFICATION_SERVER_OPTIONTHREE_H
#define KNN_CLASSIFICATION_SERVER_OPTIONTHREE_H


#include "Command.h"
#include "../utilities/KNN.h"
class OptionThree : public Command{
private:
    KNN* knn;
public:
    OptionThree();
    OptionThree(DefaultIO *dio,KNN* knn);
    void execute() override;
};

#endif //KNN_CLASSIFICATION_SERVER_OPTIONTHREE_H
