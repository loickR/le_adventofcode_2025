#ifndef _PSYUME_H
#define _PSYUME_H

#include <vector>
#include <string>
#include "Data.h"

class FileParser {

private:
    FileParser();

    ~FileParser();

public:
    static std::vector<Data> getLinesFromFile(std::string const& file);


};

#endif