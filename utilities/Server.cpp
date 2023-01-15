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
int main()
{
    list<thread> treads;
    for (auto tread: treads) {
        DefaultIO dio = DefaultIO dio;
        CLI cli=CLI cli(dio);
        tread=tread(cli.start());
    }
    return 0;

}