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

    std::vector<std::string> splitString(std::string const& delimiter) const;

    std::vector<int> getIntValues() const;

    bool operator==(Data const& d);

    int compareSideBySide(int limit);

    ~Data();
};

#endif