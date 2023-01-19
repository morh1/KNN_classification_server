//
// Created by mor on 1/13/23.
//

#include "OptionThree.h"

OptionThree::OptionThree(DefaultIO *dio,KNN &knn) {
    this->dio = dio;
    this->knn= knn;
    this->description ="3. classify data";
}
OptionThree ::OptionThree() {
}

void OptionThree::execute() {
    if(!this->knn.validData){
        this->dio->write(PS_UPLOAD);
        //cli.start??????????????????????????????
    }
    this->knn.createClassificationStr();
    // create a paramer in knn? convert information
    this->dio->write(COMPLETE);
}
