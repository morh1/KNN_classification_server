#include "OptionThree.h"
/**
*  OptionThree constructor initial the parameters
* @param (DefaultIO * dio,KNN* knn)
*/
OptionThree::OptionThree(DefaultIO *dio,KNN*knn) {
    this->dio = dio;
    this->knn= knn;
    this->description ="3. classify data";
}
/**
 *  default constructor
 */
OptionThree ::OptionThree() {}
/**
 *  creates the classification string
 */
void OptionThree::execute() {
    string classification;
    //if there is no data
    if(!(this->knn->getValidData())){
        this->dio->write(PS_UPLOAD);
        return;
    }
    if(this->knn->getClassification().empty()){
        this->knn->classification();
    }
    this->dio->write(COMPLETE);
}
