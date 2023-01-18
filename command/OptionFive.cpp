//
// Created by mor on 1/13/23.
//

#include "OptionFive.h"
#include "OptionOne.h"
OptionFive::OptionFive(DefaultIO *dio,KNN &knn) {
    this->dio = dio;
    this->knn= knn;
    this->description ="opt five desc";
}
OptionFive ::OptionFive() {}


void OptionFive::execute() {

}
