#include "OptionFour.h"
/**
**
*  OptionFour constructor initial the parameters
*
* @param (DefaultIO * dio,KNN* knn)
*/
OptionFour::OptionFour(DefaultIO *dio,KNN* knn) {
    this->dio = dio;
    this->knn= knn;
    this->description ="4. display results";
}
/**
 *  default constructor
 */
OptionFour ::OptionFour() {}
/**
 *  print the classification string
 */
void OptionFour::execute(){
    //if there is no data
    if(!this->knn->getValidData()){
        this->dio->write(PS_UPLOAD);
        return;
    }
    //if there is no classification string
    if(!(this->knn->getClassification().size())){
        this->dio->write(CLASSIFY);
        return;
    }
    this->dio->write(this->knn->getClassification() +"Done.");

}
