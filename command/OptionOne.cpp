#include "OptionOne.h"

OptionOne::OptionOne(DefaultIO * dio,KNN &knn) {
    this->dio = dio;
    this->knn= knn;
    this->description = "1. upload an unclassified csv data file";
}
OptionOne ::OptionOne(){

}

void OptionOne::execute() {
    string labeled_line, unlabeled_line,labeled_str,unlabeled_str;
    //asks for a csv path of the classified vectors
    this->dio->write(UPLOAD_CSV_TRAIN);
    //gets the csv content as a string
    labeled_line = this->dio->read();
    while(labeled_line!="/n"){
        labeled_str.append(labeled_line);

    }
    //asks for a csv path of the unclassified vectors
    this->dio->write(UPLOAD_CSV_TEST);
    //gets the csv content as a string
    unlabeled_line = this->dio->read();
    //insert the string into the knn data
    this->knn.loadVectorsList(labeled_line,unlabeled_line);
    //if the data is valid
    if(!(this->knn.validData)){
        return;
    }

}
