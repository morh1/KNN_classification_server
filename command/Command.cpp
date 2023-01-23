#include <iostream>
#include "Command.h"


Command::Command() {

}
/**
**
* the function send to the client the description of each command object.
*/
void Command::printDescription() {
    this->dio->write(this->description);
}