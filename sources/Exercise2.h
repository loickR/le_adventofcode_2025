#ifndef _EXERCISE2_H
#define _EXERCISE2_H

#include "IExercise.h"

#include <string>

class Exercise2 : public IExercise {

private:
    int wrongIdsCount;

public:
    Exercise2();

    void run(std::string const& filename);

    int readWrongIdsCount() const;

    void doExecute();

    ~Exercise2();
};

#endif