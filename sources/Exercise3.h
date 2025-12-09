#ifndef _EXERCISE3_H
#define _EXERCISE3_H

#include "IExercise.h"

#include <string>
#include <vector>

class Exercise3 : public IExercise {

private:
    int joltage;

    int get_index_of_max(std::vector<int> const& vec);

public:
    Exercise3();

    void run(std::string const& filename);

    int readJoltage() const;

    void doExecute();

    ~Exercise3();
};

#endif