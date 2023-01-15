//
// Created by mor on 1/15/23.
//
#include <list>
#include <thread>
#include "Server.h"
#include "../runner/CLI.h"
#include "../IO/DefaultIO.h"
using namespace std;
void createCLI(){

}
using namespace std;
int main()
{
    list<thread> treads;

    StandardIO dio =StandardIO();
    CLI cli = CLI(dio);
    thread t;
    //t = thread(cli.start());

    return 0;

}