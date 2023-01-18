//
// Created by mor on 1/13/23.
//

#include "OptionThree.h"

OptionThree::OptionThree(DefaultIO *dio,KNN &knn) {
    this->dio = dio;
    this->knn= knn;
    this->description ="3. classify data";
}
OptionThree ::OptionThree() {}

void OptionThree::execute() {

}
