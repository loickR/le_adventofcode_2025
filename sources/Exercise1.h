//
// Created by payum on 08/11/2025.
//

#ifndef LE_ADVENTOFCODE_2025_EXERCICE1_H
#define LE_ADVENTOFCODE_2025_EXERCICE1_H

#include "IExercise.h"

#include <string>

struct Position {
    int currentDial;
    int sum;
};

class Exercise1 : public IExercise {

private:
    void run(std::string const& filename);

    void moveLeft(Position& pos, int currentPos, int newPos, int min, int max);

    void moveRight(Position& pos, int currentPos, int newPos, int max);
protected:
    void doSample();

    void doExercice1P1();

public:
    Exercise1();

    void doExecute();

~Exercise1();
};


#endif //LE_ADVENTOFCODE_2025_EXERCICE1_H