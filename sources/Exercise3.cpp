#include "Exercise3.h"

#include <iostream>
#include <psyume.h>

Exercise3::Exercise3() : joltage(0) {

}

void Exercise3::run(std::string const& filename) {
    std::vector<Data> lines = FileParser::getLinesFromFile(filename);

    for (Data data : lines) {
        std::vector<int> batteries = data.getIntValues();
        std::vector<int> copyBatteries = data.getIntValues();

        int firstBattery = *std::max_element(batteries.begin(), batteries.end());
        std::cout << "firstBattery = " << firstBattery << std::endl;
        int firstIndex = get_index_of_max(batteries);
        copyBatteries[firstIndex] = -1;

        int secondBattery = -1;
        for (int i = 0; i < batteries.size(); i++) {
            secondBattery = *std::max_element(std::begin(copyBatteries), std::end(copyBatteries));
            int secondIndex = get_index_of_max(copyBatteries);

            if (secondIndex < firstIndex) {
            }

        }

        std::cout << std::endl;
    }
}

int Exercise3::readJoltage() const {
    return this->joltage;
}

int Exercise3::get_index_of_max(std::vector<int> const& vec) {
    int firstBattery = *std::max_element(vec.begin(), vec.end());
    std::cout << "firstBattery = " << firstBattery << std::endl;
    int firstIndex = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == firstBattery) {
            firstIndex = i;
            std::cout << "firstIndex = " << firstIndex << std::endl;
            break;
        }
    }

    return firstIndex;
}

void Exercise3::doExecute() {
    
}

Exercise3::~Exercise3() {

}