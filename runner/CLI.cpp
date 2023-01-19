#include "CLI.h"

void CLI::start() {
    this->opt1.execute();
    //asks for a csv path of the classified vectors
    this->dio->write("Welcome to the KNN Classifier main. Please choose an option:");
    for (auto  command : this->comList) {
        command->printDescription();
    }
}

CLI::CLI(DefaultIO *dio){
this->dio = dio;
this->opt1 = OptionOne(dio,knn);
this->opt2 = OptionTwo(dio,knn);
this->opt3 = OptionThree(dio,knn);
this->opt4 = OptionFour(dio,knn);
this->opt5 = OptionFive(dio,knn);
this->opt8 = OptionEight(dio,knn);
this->comList.push_back(&this->opt1);
this->comList.push_back(&this->opt2);
this->comList.push_back(&this->opt3);
this->comList.push_back(&this->opt4);
this->comList.push_back(&this->opt5);
this->comList.push_back(&this->opt8);

}