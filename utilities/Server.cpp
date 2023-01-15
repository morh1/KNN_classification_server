//
// Created by mor on 1/15/23.
//
#include <list>
#include <thread>
#include "Server.h"
using namespace std;
void createCLI(){

}
int main()
{
    list<thread> treads;
    for (auto tread: treads) {
        tread=tread(createCLI);
    }
    return 0;

}