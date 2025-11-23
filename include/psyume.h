#ifndef _PSYUME_H
#define _PSYUME_H

#include <vector>
#include <string>

class FileParser {

private:
    FileParser();

    ~FileParser();

public:
    static std::vector<std::string> get_lines_from_file(std::string const& file);


};

#endif