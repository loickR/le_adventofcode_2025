#include "Exercise2.h"

#include <psyume.h>
#include <iostream>
#include <vector>

Exercise2::Exercise2() : wrongIdsCount(0) {

}

void Exercise2::run(std::string const& filename) {
   std::vector<Data> lines = FileParser::getLinesFromFile(filename);
   std::vector<std::string> splittingLines = lines[0].splitString(',');
   
   for (std::string const& str : splittingLines) {
        Data data(str);
        std::vector<std::string> strParsed = data.splitString('-');

        std::string strId1 = strParsed[0];
        std::string strId2 = strParsed[1];

        if (strId1.at(0) == '0' || strId2.at(0) == '0') {
            break;
        }

        int id1 = stoi(strId1);
        int copyId1 = id1;
        int id2 = stoi(strId2);
        int size = abs(id2 - id1);
        int array[size + 1];
        for (int i = 0; i <= size; i++) {
            array[i] = copyId1;
            copyId1++;
        }

        std::vector<int> wrongIdsList;
        for (int i = 0; i <= size; i++) {
            int value = array[i];
            std::string str = std::to_string(value);
            //std::cout << "reading value " << str << std::endl;

            if (str.at(0) == '0') {
                break;
            }
            
            std::vector<std::string> listsubstr;
            int subSize = str.length() / 2;
            
            for (int k = 0; k < str.length(); k+=subSize) {
                std::string subStr = str.substr(k, subSize);
                //std::cout << "splitting value = "  << subStr << std::endl;
                listsubstr.push_back(subStr);
            }

            bool duplicated = true;
            for (int k = 0; k < listsubstr.size(); k++) {
                int n = k;
                int kp1 = n + 1;
                
                if (kp1 > listsubstr.size()) {
                    break;
                }
                
                std::string currentN = listsubstr[n];
                std::string currentN1 = listsubstr[kp1];

                if (currentN1.empty()) {
                    break;
                }

                std::cout << "Comparing " << currentN << " to " << currentN1 << std::endl;

                duplicated = currentN == currentN1;
            }

            if (duplicated) {
                wrongIdsList.push_back(value);
            }
            else if (value % 11 == 0) {
                wrongIdsList.push_back(value);
            }
        }

        int wrongSize = wrongIdsList.size();
        for (int val : wrongIdsList) {
            this->wrongIdsCount += val;
        }

        this->wrongIdsCount += wrongSize;
        std::cout << strId1 << "-" << strId2 << " has " << wrongSize << " invalids IDs : " << std::endl;
        for (int val : wrongIdsList) {
            std::cout << "wrong=" << val << std::endl;
        }
   }

   std::cout << "Adding up all the invalid IDs produces " << this->readWrongIdsCount() << std::endl;
}

int Exercise2::readWrongIdsCount() const {
    return this->wrongIdsCount;
}

void Exercise2::doExecute() {
    run("exercises/sample2.txt");
}

Exercise2::~Exercise2() {
    
}