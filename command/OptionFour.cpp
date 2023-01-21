//
// Created by mor on 1/13/23.
//

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
    list<string> classification=this->knn->getClassification();
    //if there is no classification list
    if(classification.empty()){
        this->dio->write(CLASSIFY);
        return;
    }
    //creates the string
    string classification_str;
    int counter=0;
    while(!classification.empty()){
        counter++;
        classification_str.append(to_string(counter)+"\t"+classification.front()+"\n");
        classification.pop_front();
    }
    this->dio->write(classification_str);

}
