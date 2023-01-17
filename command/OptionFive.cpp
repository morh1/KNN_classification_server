//
// Created by mor on 1/13/23.
//

#include "OptionFive.h"
OptionFive::OptionFive(DefaultIO &dio,KNN &knn) {
    this->dio = &dio;
    this->knn= knn;
}
OptionFive ::OptionFive() {}


void OptionFive::printDescription() {
    this->dio->write(this->description);
}


void OptionFive::execute() {}
