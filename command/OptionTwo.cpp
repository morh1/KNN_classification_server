//
// Created by mor on 1/13/23.
//

#include "OptionTwo.h"

OptionTwo::OptionTwo(DefaultIO &dio,KNN &knn) {
    this->dio = &dio;
    this->knn= knn;
}
OptionTwo ::OptionTwo() {}


void OptionTwo::printDescription() {
    this->dio->write(this->description);
}
void OptionTwo::execute() {
    string input;
    //display the knn parameters
    cout<<"The current KNN parameters are: K = "<<this->knn.getK()<<", distance metric = "<<this->knn.getMat();
    //gets the input string
    input = this->dio->read();
    if(input!="/n"){
        bool met=false,bool k=false;
        list<string> lsInput = Utilities::separateInput(string str_input);
        if(atoi(lsInput.front())){
            k=true;
        }
        else{
            his->dio->write(ERROR_K);
        }
        if(Utilities::validDisStr(lsInput.back())){
            met=true;
        }
        else{
            this->dio->write(ERROR_MET);
        }
        if(met && k){
            this->knn.setK(lsInput.front());
            this->knn.setMat(lsInput.back());
        }

    }
    string labeled_str, unlabeled_str;
    //asks for a csv path of the classified vectors
    this->dio->write(UPLOAD_CSV_TRAIN);
    //gets the csv content as a string
    labeled_str = this->dio->read();
    //asks for a csv path of the unclassified vectors
    this->dio->write(UPLOAD_CSV_TEST);
    //gets the csv content as a string
    unlabeled_str = this->dio->read();
    //insert the string into the knn data
    this->knn.loadVectorsList(labeled_str, unlabeled_str);
    //if the data is valid
    if (!(this->knn.validData)) {
        return;
    }
}