#include <iostream>
#include "Command.h"


Command::Command() {

}

void Command::printDescription() {
    this->dio->write(this->description);
}