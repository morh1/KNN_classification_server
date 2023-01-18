#include "OptionTwo.h"
#include "Utilities.h"


OptionTwo::OptionTwo(DefaultIO *dio,KNN &knn) {
    this->dio = dio;
    this->knn= knn;
    this->description ="opt two desc";
}
//OptionTwo ::OptionTwo() = default;



void OptionTwo::execute() {
    string input;
    //display the knn parameters
    cout<<"The current KNN parameters are: K = "<<this->knn.getK()<<", distance metric = "<<this->knn.getMat();
    //gets the input string
    input = this->dio->read();
    if(input!="/n"){
        bool met=false,k=false;
        list<string> lsInput = Utilities::separateInput(dio->read());
        if(stoi(lsInput.front())){
            k=true;
        }
        else{
            this->dio->write(ERROR_K);
        }
        if(Utilities::validDisStr(lsInput.back())){
            met=true;
        }
        else{
            this->dio->write(ERROR_MET);
        }
        if(met && k){
            this->knn.setK(stoi(lsInput.front()));
            this->knn.setMat(lsInput.back());
        }

    }
    /*
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
     */
}

OptionTwo::OptionTwo() {

}