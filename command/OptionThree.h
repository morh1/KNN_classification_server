#ifndef KNN_CLASSIFICATION_SERVER_OPTIONTHREE_H
#define KNN_CLASSIFICATION_SERVER_OPTIONTHREE_H
#include "Command.h"
#include "../utilities/KNN.h"
class OptionThree : public Command{
private:
    KNN* knn;
public:
/**
 *  default constructor
 */
    OptionThree();
/**
*  OptionThree constructor initial the parameters
* @param (DefaultIO * dio,KNN* knn)
*/
    OptionThree(DefaultIO *dio,KNN* knn);
/**
 *  creates the classification string
 */
    void execute() override;
};

#endif //KNN_CLASSIFICATION_SERVER_OPTIONTHREE_H
