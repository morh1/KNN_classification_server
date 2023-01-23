#ifndef KNN_CLASSIFICATION_SERVER_OPTIONFOUR_H
#define KNN_CLASSIFICATION_SERVER_OPTIONFOUR_H

#include "Command.h"
#include "../utilities/KNN.h"
class OptionFour : public Command{
private:
    KNN* knn;
public:
/**
 *  default constructor
 */
    OptionFour();
/**
*  OptionFour constructor initial the parameters
* @param (DefaultIO * dio,KNN* knn)
*/
    OptionFour(DefaultIO *dio,KNN* knn);
/**
 *  print the classification string
 */
    void execute() override;
};
#endif //KNN_CLASSIFICATION_SERVER_OPTIONFOUR_H
