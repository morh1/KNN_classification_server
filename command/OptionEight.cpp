//
// Created by mor on 1/13/23.
//

#include "OptionEight.h"
OptionEight::OptionEight(DefaultIO *dio,KNN &knn) {
    this->dio = dio;
    this->knn= knn;
    this->description ="opt eight desc";
}
OptionEight ::OptionEight() {}

void OptionEight::execute() {}