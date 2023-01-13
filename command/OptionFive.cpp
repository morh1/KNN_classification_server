//
// Created by mor on 1/13/23.
//

#include "OptionFive.h"
class OptionFive: public Command {
private:
    Operations *operation;

public:
    OptionFive(Operations *operation){this.operation=operation;}

    void execute() {
        operation->downloadResults();
    }
};