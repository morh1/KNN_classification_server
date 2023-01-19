//
// Created by mor on 1/15/23.
//
#include <list>
#include <thread>
#include "main.h"
#include "../runner/CLI.h"
//#include "../IO/DefaultIO.h"
#include "../IO/StandardIO.h"
using namespace std;
void createCLI(){

}

int main()
{
    //list<thread> treads;

    StandardIO dio= StandardIO();
    CLI cli = CLI(&dio);
    //thread t;
    cli.start();
    return 0;

}