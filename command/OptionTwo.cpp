#include "OptionTwo.h"
#include "Utilities.h"
using namespace std;


OptionTwo::OptionTwo(DefaultIO *dio,KNN &knn) {
    this->dio = dio;
    this->knn= knn;
    this->description ="2. algorithm settings";
}
//OptionTwo ::OptionTwo() = default;



void OptionTwo::execute() {
    string input;
    //display the knn parameters
    this->dio->write("The current KNN parameters are: K = "+ to_string(this->knn.getK()) + ", distance metric = " + this->knn.getMat());
    //gets the input string
    input = this->dio->read();
    if(input!="/n"){
        bool met=false,k=false;
        list<string> lsInput = Utilities::separateInput(dio->read());
        if(Utilities::validInt(lsInput.front())){
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
}

OptionTwo::OptionTwo() {

}