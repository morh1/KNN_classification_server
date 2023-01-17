//
// Created by mor on 1/13/23.
//

#include "OptionEight.h"
OptionEight::OptionEight(DefaultIO &dio,KNN &knn) {
    this->dio = &dio;
    this->knn= knn;
}
OptionEight ::OptionEight() {}


void OptionEight::printDescription() {
    this->dio->write(this->description);
}


void OptionEight::execute() {}