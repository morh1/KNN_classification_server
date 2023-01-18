#include "CLI.h"

void CLI::start() {

    this->opt1.execute();
}

CLI::CLI(DefaultIO *dio){
this->dio = dio;
this->opt1 = OptionOne(dio,knn);
this->opt2 = OptionTwo(dio,knn);
this->opt3 = OptionThree(dio,knn);
this->opt4 = OptionFour(dio,knn);
this->opt5 = OptionFive(dio,knn);
this->opt8 = OptionEight(dio,knn);

// (this->comList).push_back(opt1);
}