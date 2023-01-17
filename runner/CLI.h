#ifndef KNN_CLASSIFICATION_SERVER_CLI_H
#define KNN_CLASSIFICATION_SERVER_CLI_H

#include "../IO/DefaultIO.h"
#include "../IO/StandardIO.h"
#include "../command/Command.h"
#include "../command/OptionOne.h"
#include "../command/OptionTwo.h"
#include "../command/OptionThree.h"
#include "../command/OptionFour.h"
#include "../command/OptionFive.h"
#include "../command/OptionEight.h"
#include "../utilities/KNN.h"


/**
 * the command line interface class ,hold the relevand data for each client includ the IO settings,
 * and the algorithem settings.
 */
class CLI {

    StandardIO dio;
    KNN knn;

    OptionOne opt1;
    OptionTwo opt2;
    OptionFour opt4;
    OptionFive opt5;
    OptionEight opt8;
    list<Command> comList;

public:
     CLI(StandardIO dio){
        this->dio =dio;
        this->opt1 = OptionOne(&dio,&knn);
        //this->comList.push_back(opt1);
    }
    void start();



};


#endif //KNN_CLASSIFICATION_SERVER_CLI_H
