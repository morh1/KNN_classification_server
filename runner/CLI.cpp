#include "CLI.h"

void CLI::start() {
    this->opt1.printDescription();

}

CLI::CLI(DefaultIO *dio){
this->dio = dio;
this->opt1 = OptionOne(dio,knn);
// (this->comList).push_back(opt1);
}