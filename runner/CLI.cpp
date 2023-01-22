
#include "CLI.h"
using namespace std;
/**
 * create the menu and receive a option from the user
 */
void CLI::start() {
    string str  = "Welcome to the KNN Classifier Server. Please choose an option:";
    for ( Command* command: this->comArray) {
        str+= "\n";
        str += command->description;
    }
    while(true){
        this->dio->write(str);
        //check if the string is one char and this char between 1-6 and 8 (ascii table values)
        string input=this->dio->read();
        //first char
        char c = input[0];
        if(input.length()==1 && ((c>=49 && c<=53) || c<=56)){
            //the user choose 8
            if(c==56){
                this->comArray[5]->execute();
                return;
            }
            else{
                this->comArray[c-49]->execute();
            }
        }
        else{
            this->dio->write(ERROR);
        }
    }
}
/**
 * initial the cli option array
 *
 * @param (DefaultIO *dio)
 */
CLI::CLI(DefaultIO *dio){
    this->dio = dio;
    this->opt1 = OptionOne(dio,&knn);
    this->opt2 = OptionTwo(dio,&knn);
    this->opt3 = OptionThree(dio,&knn);
    this->opt4 = OptionFour(dio,&knn);
    this->opt5 = OptionFive(dio,&knn);
    this->opt8 = OptionEight(dio,&knn);
    //initial the array
    this->comArray[0]=(&this->opt1);
    this->comArray[1]=(&this->opt2);
    this->comArray[2]=(&this->opt3);
    this->comArray[3]=(&this->opt4);
    this->comArray[4]=(&this->opt5);
    this->comArray[5]=(&this->opt8);
}