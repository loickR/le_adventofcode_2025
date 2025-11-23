#include "SampleExercise.h"

#include <vector>
#include <string>
#include <psyume.h>

#include <iostream>

SampleExercise::SampleExercise() {

}

void SampleExercise::doExecute() {
    std::cout << "This is an example" << std::endl;

    std::vector<std::string> lines = FileParser::get_lines_from_file("../exercises/exemple.txt");
    for (std::string aLine : lines) {
        std::cout << aLine << std::endl;
    }
}

SampleExercise::~SampleExercise() {

}