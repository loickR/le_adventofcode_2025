//
// Created by payum on 08/11/2025.
//

#include "Exercise1.h"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <psyume.h>

Exercise1::Exercise1() : password(0) {

}

void Exercise1::run(std::string const& filename) {
    std::vector<Data> lines = FileParser::getLinesFromFile(filename);

    int currentDial = 50;
    int password = 0;
    int min = 0;
    int max = 100;
    int sum = max;

    int size = lines.size();

    std::cout << "The dial starts by pointing at " << currentDial << std::endl;

    Position pos;
    pos.currentDial = currentDial;
    pos.sum = sum;
    pos.divide = 0;

    for (int i = 0; i < size; i++) {
        Data data = lines[i];
        std::cout << "The dial is rotated " << data.getLine();

        char direction = data.getLine().at(0);
        std::string numberStr = data.getLine().substr(1);
        int newPos = stoi(numberStr);
        
        rotate(pos, direction, newPos, min, max);

        currentDial = pos.currentDial;
        sum = pos.sum;

        std::cout << " to point at " << abs(currentDial) << std::endl;
        if (currentDial >= 100 || currentDial <= 0) {
            password++;
            //password += password * pos.divide;
            pos.currentDial = 0;
            pos.sum = 0;
            pos.divide = 0;
        }
    }

    this->password = password;
    std::cout << "The password is : " << password << std::endl;

}

void Exercise1::run2(std::string const& filename) {
    std::vector<Data> lines = FileParser::getLinesFromFile(filename);

    int currentDial = 50;
    int password = 0;
    int min = 0;
    int max = 100;
    int sum = max;

    int size = lines.size();

    std::cout << "The dial starts by pointing at " << currentDial << std::endl;

    Position pos;
    pos.currentDial = currentDial;
    pos.sum = sum;
    pos.divide = 0;

    for (int i = 0; i < size; i++) {
        Data data = lines[i];
        std::cout << "The dial is rotated " << data.getLine();

        char direction = data.getLine().at(0);
        std::string numberStr = data.getLine().substr(1);
        int newPos = stoi(numberStr);
        
        rotate(pos, direction, newPos, min, max);

        currentDial = pos.currentDial;
        sum = pos.sum;

        std::cout << " to point at " << abs(currentDial) << std::endl;
        if ((currentDial >= 100 || currentDial <= 0) && pos.divide != 0) {
            password += 1 + password * pos.divide;
            pos.currentDial = 0;
            pos.sum = 0;
        }
    }

    this->password = password;
    std::cout << "The password is : " << password << std::endl;
}

void Exercise1::rotate(Position& pos, char direction, int newPos, int min, int max) {
    switch (direction) {
        case 'L':
            moveLeft(pos, newPos, min, max);
            break;
        case 'R':
            moveRight(pos, newPos, max);
            break;
        default:
            break;
    }
}

void Exercise1::moveLeft(Position& pos, int newPos, int min, int max) {
    int divide = newPos % max;
    int currentDial = pos.currentDial - divide;
    std::cout << " moveLeft -> divide = " << divide << std::endl;
    int sum = abs(currentDial);
    int quotient = sum / max;
    std::cout << " moveLeft -> quotient = " << quotient << std::endl;

    if (currentDial <= min) {
        currentDial = max + currentDial;
    }

    pos.currentDial = currentDial;
    pos.sum = sum;
    pos.divide = quotient;
}

void Exercise1::moveRight(Position& pos, int newPos, int max) {
    int divide = newPos % max;
    int currentDial = pos.currentDial + divide;
    std::cout << "moveRight -> divide = " << divide << std::endl;
    int sum = abs(currentDial);
    int quotient = sum / max;
    std::cout << " moveRight -> quotient = " << quotient << std::endl;

    if (currentDial >= max) {
        currentDial = currentDial - max;
    }

    pos.currentDial = currentDial;
    pos.sum = sum;
    pos.divide = quotient;
}

void Exercise1::doExercice1P1() {
    run("../exercises/exercice1_p1.txt");
}

void Exercise1::doExercice1P2() {
    run2("exercises/exercice1_p1.txt");
}

void Exercise1::doSample() {
    run("exercises/sample.txt");
}

void Exercise1::doSample2() {
    run2("exercises/sample.txt");
}

void Exercise1::doExecute() {
   doSample();

   //doExercice1P1();

   //doSample2();

   //doExercice1P2();
}

int Exercise1::readPassword() const {
    return this->password;
}

Exercise1::~Exercise1() {

}
