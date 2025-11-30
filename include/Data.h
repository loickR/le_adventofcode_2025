#ifndef _DATA_H
#define _DATA_H

#include <string>
#include <vector>

class Data {

private:
    std::string line;

public:
    Data(std::string const& line);

    std::string getLine() const;

    std::vector<std::string> splitString(char const& delimiter) const;

    std::vector<int> getIntValues() const;

    std::vector<int> getIntValuesFromStr(std::string const& str) const;

    bool operator==(Data const& d);

    std::vector<int> compareSideBySide(int limit) const;

    ~Data();
};

#endif