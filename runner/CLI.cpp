#include "CLI.h"

void CLI::start() {
    int  int_input;
    while(true){
        this->dio->write("Welcome to the KNN Classifier Server. Please choose an option:");
        for ( Command* command: this->comArray) {
            command->printDescription();
        }
        int_input=stoi(this->dio->read());
        if(1<=int_input && int_input<=5 || int_input ==8){
            if(int_input==8) {
                this->comArray[5]->execute();
                return;
            }
            this->comArray[int_input-1]->execute();
        }
        else{
            this->dio->write(ERROR);
        }
    }
}

CLI::CLI(DefaultIO *dio){
    this->dio = dio;
    this->opt1 = OptionOne(dio,&knn);
    this->opt2 = OptionTwo(dio,&knn);
    this->opt3 = OptionThree(dio,&knn);
    this->opt4 = OptionFour(dio,&knn);
    this->opt5 = OptionFive(dio,&knn);
    this->opt8 = OptionEight(dio,&knn);
    this->comArray[0]=(&this->opt1);
    this->comArray[1]=(&this->opt2);
    this->comArray[2]=(&this->opt3);
    this->comArray[3]=(&this->opt4);
    this->comArray[4]=(&this->opt5);
    this->comArray[5]=(&this->opt8);
}