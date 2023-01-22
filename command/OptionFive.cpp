#include "OptionFive.h"
/**
**
*  OptionFive constructor initial the parameters
*
* @param (DefaultIO * dio,KNN* knn)
*/
OptionFive::OptionFive(DefaultIO *dio,KNN* knn) {
    this->dio = dio;
    this->knn= knn;
    this->description ="5. download results";
}
/**
 *  default constructor
 */
OptionFive ::OptionFive() {
}
/**
 *  write the classification string
 */
void OptionFive::execute() {
    //if there is no data
    if(!this->knn->getValidData()){
        //flag to the client it wiil not get a data
        this->dio->write("false");
        this->dio->write(PS_UPLOAD);
        return;
    }
    //if there is no classification string
    if(!(this->knn->getClassification().size())){
        //flag to the client it wiil not get a data
        this->dio->write("false");
        this->dio->write(CLASSIFY);
        return;
    }
    this->dio->write("true");
    this->dio->write(this->knn->getClassification());
}
