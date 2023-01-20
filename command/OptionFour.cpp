//
// Created by mor on 1/13/23.
//

#include "OptionFour.h"
OptionFour::OptionFour(DefaultIO *dio,KNN* knn) {
    this->dio = dio;
    this->knn= knn;
    this->description ="4. display results";
}
OptionFour ::OptionFour() {}

void OptionFour::execute(){
    if(!this->knn->getValidData()){
        this->dio->write(PS_UPLOAD);
        return;
    }
    list<string> classification=this->knn->getClassification();
    if(classification.empty()){
        this->dio->write(CLASSIFY);
        return;
    }
    string classification_str;
    int counter=0;
    while(!classification.empty()){
        counter++;
        classification_str.append(to_string(counter)+"\t"+classification.front()+"\n");
        classification.pop_front();
    }
    this->dio->write(classification_str);

}
