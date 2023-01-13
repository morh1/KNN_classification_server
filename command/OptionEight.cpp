//
// Created by mor on 1/13/23.
//

#include "OptionEight.h"
class OptionEight: public Command {
private:
    Operations *operation;

public:
    OptionEight(Operations  *operation){this.operation=operation;}

    void execute() {
        operation->exit();
    }
};