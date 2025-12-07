#ifndef _EXERCISE2_H
#define _EXERCISE2_H

#include "IExercise.h"

#include <string>

bool repeatDigit(long number);

class Exercise2 : public IExercise {

private:
    long wrongIdsCount;

public:
    Exercise2();

    void run(std::string const& filename);

    void run2(std::string const& filename);

    long readWrongIdsCount() const;

    void doExecute();

    ~Exercise2();
};

#endif