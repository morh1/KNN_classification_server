#include "OptionTwo.h"
#include "Utilities.h"
using namespace std;
/**
**
*  OptionTwo constructor initial the parameters
*
* @param (DefaultIO * dio,KNN* knn)
*/
OptionTwo::OptionTwo(DefaultIO *dio,KNN* knn) {
    this->dio = dio;
    this->knn= knn;
    this->description ="2. algorithm settings";
}
/**
 *  represents and updates the knn matric and the number of neighbors if required.
 */
void OptionTwo::execute() {
    string input;
    //display the knn parameters
    this->dio->write("The current KNN parameters are: K = "+ to_string(this->knn->getK()) + ", distance metric = " + this->knn->getMat());
    //gets the input string
    input = this->dio->read();
    //isn't enter
    if(!input.empty()){
        bool met=false,k=false;
        list<string> lsInput = Utilities::separateInput(input);
        //the k value is valid
        if(Utilities::validInt(lsInput.front())){
            if(stoi(lsInput.front())>this->knn->getVectNum()){
                //
                this->dio->write("false");
                this->dio->write(ERROR_K);
            }
            else{
                this->dio->write("true");
                k=true;
            }
        }
        else{
            this->dio->write("false");
            this->dio->write(ERROR_K);
        }
        //the matric is valid
        if(Utilities::validDisStr(lsInput.back())){
            this->dio->write("true");
            met=true;
        }
        else{
            this->dio->write("false");
            this->dio->write(ERROR_MET);
        }
        //sets if they both valid
        if(met && k){
            this->knn->setK(stoi(lsInput.front()));
            this->knn->setMat(lsInput.back());
        }
    }
}

OptionTwo::OptionTwo() {

}