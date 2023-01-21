//
// Created by mor on 1/13/23.
//
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
    this->dio->write(this->knn->getClassification());
}
