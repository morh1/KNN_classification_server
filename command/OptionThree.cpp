//
// Created by mor on 1/13/23.
//

#include "OptionThree.h"
OptionThree::OptionThree(DefaultIO &dio,KNN &knn) {
    this->dio = &dio;
    this->knn= knn;
}
OptionThree ::OptionThree() {}


void OptionThree::printDescription() {
    this->dio->write(this->description);
}


void OptionThree::execute() {}

