//
// Created by mor on 1/13/23.
//

#include "OptionFour.h"
OptionFour::OptionFour(DefaultIO &dio,KNN &knn) {
    this->dio = &dio;
    this->knn= knn;
}
OptionFour ::OptionFour() {}


void OptionFour::printDescription() {
    this->dio->write(this->description);
}


void OptionFour::execute() {}

