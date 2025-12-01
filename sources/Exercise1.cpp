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

void Exercise1::doExecute() {

    std::vector<Data> lines = FileParser::getLinesFromFile("../exercises/sample.txt");

    int currentDial = 50;
    int password = 0;
    int min = 0;
    int max = 100;
    int sum = max;

    for (int i = 0; i < lines.size(); i++) {
        Data data = lines[i];
        std::cout << "The dial is rotated " << data.getLine() << std::endl;

        char direction = data.getLine().at(0);
        std::string numberStr = data.getLine().substr(1);
        int number = stoi(numberStr);

        int result = currentDial;
        if (direction == 'L') {
            if (i == 0) {
                currentDial = max - abs(currentDial - number);
            }
            else {
                currentDial = abs(currentDial - number);
                sum = currentDial;

                if (currentDial < 0) {
                    currentDial = max - currentDial;
                }
            }
        }
        else if (direction == 'R') {
            if (i == 0) {
                currentDial = max + abs(currentDial - number);
            }
            else {
                currentDial = abs(currentDial + number);
                sum = currentDial;
                if (currentDial > 100) {
                    currentDial = currentDial - max;
                }
            }
        }

        std::cout << "to point at " << currentDial << std::endl;
        if (sum == 100 || sum == 0) {
            password++;
        }
    }

    std::cout << "The password is : " << password << std::endl;
}

Exercise1::~Exercise1() {

}
