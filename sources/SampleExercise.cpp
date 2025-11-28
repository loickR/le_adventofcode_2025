#include "SampleExercise.h"

#include <vector>
#include <string>
#include <psyume.h>

#include <iostream>

SampleExercise::SampleExercise() {

}

void SampleExercise::doExecute() {
    std::cout << "This is an example" << std::endl;

    std::vector<Data> lines = FileParser::getLinesFromFile("../exercises/exemple.txt");
    for (Data aLine : lines) {
        std::cout << aLine.getLine() << std::endl;
    }

    std::vector<Data> lines2 = FileParser::getLinesFromFile("../exercises/exemple2.txt");
    for (Data d : lines2) {
      //  std::cout << d.getLine() << std::endl;

        std::vector<std::string> val = d.splitString(' ');
    }
}

SampleExercise::~SampleExercise() {

}