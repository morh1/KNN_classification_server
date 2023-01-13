#include "OptionOne.h"

OptionOne::OptionOne(Operations *operation) {
    this->operation=operation;
}

void OptionOne::execute() {
    string str;
    this->dio->write(UPLOAD_CSV_TRAIN);
    str = this->dio->read();
    if(str == ERROR){
        return;
    }
    this->operation->loadKnnFromStringTrain(str);
    this->dio->write(UPLOAD_CSV_TEST);
    str = this->dio->read();
    if(str == ERROR){
        return;
    }
    this->operation->loadKnnFromStringTest(str);
    if(str == ERROR){
        return;
    }
    // set init to true

}
