#include "OptionEight.h"
OptionEight::OptionEight(DefaultIO *dio,KNN* knn) {
    this->dio = dio;
    this->knn= knn;
    this->description ="8. exit";
}
OptionEight ::OptionEight() {}

void OptionEight::execute() {
}