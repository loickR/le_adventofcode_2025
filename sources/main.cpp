#include <iostream>
#include "Exercise1.h"
#include "Exercise2.h"

int main() {

    std::cout << "Welcome to Advent of Code 2025 !" << std::endl;
    
    Exercise1 exercise1;
    exercise1.doExecute();

    Exercise2 exercise2;
    exercise2.doExecute();

    return 0;
}