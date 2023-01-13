//
// Created by mor on 1/13/23.
//

#include "OptionOne.h"
class OptionOne: public Command {
private:
    Operations *operation;

public:
    OptionOne(Operations *operation){this.operation=operation;}

    void execute() {
        operation->uploadCSVDataFile();
    }
};