#include <iostream>
#include "Exercise1.h"
#include "SampleExercise.h"
#include <psyume.h>

int main() {

    std::cout << "Welcome to Advent of Code 2025 !" << std::endl;
    
    SampleExercise exercise;
    exercise.doExecute();

   FileParser::get_lines_from_file("");

    /*
    Exercise1 exercise1;
    exercise1.doExecute();
    */

    return 0;
}