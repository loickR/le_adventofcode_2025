//
// Created by payum on 08/11/2025.
//

#include "Exercise1.h"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <psyume.h>

Exercise1::Exercise1() {

}

void Exercise1::run(std::string const& filename) {
     std::vector<Data> lines = FileParser::getLinesFromFile(filename);

    int currentDial = 50;
    int password = 0;
    int min = 0;
    int max = 100;
    int sum = max;

    int size = lines.size();
    //int size = 10;

    std::cout << "The dial starts by pointing at " << currentDial << std::endl;

    Position pos;
    pos.currentDial = currentDial;
    pos.sum = sum;

    for (int i = 0; i < size; i++) {
        Data data = lines[i];
        std::cout << "The dial is rotated " << data.getLine();

        char direction = data.getLine().at(0);
        std::string numberStr = data.getLine().substr(1);
        int number = stoi(numberStr);

        if (direction == 'L') {
            moveLeft(pos, currentDial, number, min, max);
        }
        else if (direction == 'R') {
            moveRight(pos, currentDial, number, max);
        }

        currentDial = pos.currentDial;
        sum = pos.currentDial;

        std::cout << " to point at " << abs(currentDial) << std::endl;
        if (sum == 100 || sum == 0) {
            password++;
        }
    }

    std::cout << "The password is : " << password << std::endl;
}

void Exercise1::moveLeft(Position& pos, int currentPos, int newPos, int min, int max) {
    int currentDial = currentPos - newPos;
    int sum = abs(currentDial);

    //std::cout << "L -> currentDial = " << currentDial << std::endl;
    if (currentDial < min) {
        currentDial = max - sum;
    }

    pos.currentDial = currentDial;
    pos.sum = sum;
}

void Exercise1::moveRight(Position& pos, int currentPos, int newPos, int max) {
    int currentDial = currentPos + newPos;
    int sum = abs(currentDial);

    //std::cout << "R -> currentDial = " << sum << std::endl;
    if (currentDial > max) {
        int divide = sum / max;
        int modulo = divide % max;
        // std::cout << std::endl;
        // std::cout << "divide = " << divide << std::endl;
        currentDial = sum - (divide * max);
    }

    pos.currentDial = currentDial;
    pos.sum = sum;
}

void Exercise1::doExercice1P1() {
    run("exercises/exercice1_p1.txt");
}

void Exercise1::doSample() {
    run("exercises/sample.txt");
}

void Exercise1::doExecute() {
   doSample();

   //doExercice1P1();
}

Exercise1::~Exercise1() {

}
