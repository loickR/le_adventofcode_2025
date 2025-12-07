#include "Exercise2.h"

#include <psyume.h>
#include <iostream>
#include <vector>

Exercise2::Exercise2() : wrongIdsCount(0) {

}

void Exercise2::run(std::string const& filename) {
   std::vector<Data> lines = FileParser::getLinesFromFile(filename);
   std::vector<std::string> splittingLines = lines[0].splitString(',');
   
   for (int p = 0; p < splittingLines.size(); p++) {
        std::string str = splittingLines[p];
        Data data(str);
        std::vector<std::string> strParsed = data.splitString('-');

        std::string strId1 = strParsed[0];
        std::string strId2 = strParsed[1];

        if (strId2.at(0) == '0') {
            break;
        }

        if (strId1.at(0) == '0') {
            continue;
        }

        long id1 = stol(strId1);
        long copyId1 = id1;
        long id2 = stol(strId2);
        int size = abs(id2 - id1);
        std::vector<long> array;
        for (int i = 0; i <= size; i++) {
            array.push_back(copyId1);
            copyId1++;
        }

        std::vector<long> wrongIdsList;
        for (int i = 0; i <= size; i++) {
            long value = array[i];
            std::string str = std::to_string(value);
            //std::cout << "reading value " << str << std::endl;

            if (str.at(0) == '0') {
                continue;
            }
            
            if (str.length()%2 != 0) {
                continue;
            }

            std::vector<std::string> listsubstr;
            int subSize = str.length() / 2;
            for (int k = 0; k < str.length(); k+=subSize) {
                std::string subStr = str.substr(k, subSize);
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

                if (currentN1.empty() || currentN.empty()) {
                    break;
                }

               // std::cout << "Comparing " << currentN << " to " << currentN1 << std::endl;
                duplicated &= currentN == currentN1;
            }

            if (duplicated) {
                wrongIdsList.push_back(value);
            }
        }

        int wrongSize = wrongIdsList.size();
        for (long val : wrongIdsList) {
            this->wrongIdsCount += val;
        }

        std::cout << strId1 << "-" << strId2 << " has " << wrongSize << " invalids IDs : " << std::endl;
        for (int val : wrongIdsList) {
       //     std::cout << "wrong=" << val << std::endl;
        }
   }

   std::cout << "Adding up all the invalid IDs produces " << this->readWrongIdsCount() << std::endl;
}

void Exercise2::run2(std::string const& filename) {
   std::vector<Data> lines = FileParser::getLinesFromFile(filename);
   std::vector<std::string> splittingLines = lines[0].splitString(',');
   
   for (int p = 0; p < splittingLines.size(); p++) {
        std::string str = splittingLines[p];
        Data data(str);
        std::vector<std::string> strParsed = data.splitString('-');

        std::string strId1 = strParsed[0];
        std::string strId2 = strParsed[1];

        if (strId2.at(0) == '0') {
            break;
        }

        if (strId1.at(0) == '0') {
            continue;
        }

        long id1 = stol(strId1);
        long copyId1 = id1;
        long id2 = stol(strId2);
        int size = abs(id2 - id1);
        std::vector<long> array;
        for (int i = 0; i <= size; i++) {
            array.push_back(copyId1);
            copyId1++;
        }

        std::vector<long> wrongIdsList;
        for (int i = 0; i <= size; i++) {
            long value = array[i];
            std::string str = std::to_string(value);
            //std::cout << "reading value " << str << std::endl;

            if (str.at(0) == '0') {
                continue;
            }
            
            if (str.length()%2 != 0) {
                continue;
            }

            std::vector<std::string> listsubstr;
            int subSize = str.length() / 2;
            for (int k = 0; k < str.length(); k+=subSize) {
                std::string subStr = str.substr(k, subSize);
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

                if (currentN1.empty() || currentN.empty()) {
                    break;
                }

               // std::cout << "Comparing " << currentN << " to " << currentN1 << std::endl;
                duplicated &= currentN == currentN1;
            }

            if (duplicated) {
                wrongIdsList.push_back(value);
            }
        }

        int wrongSize = wrongIdsList.size();
        for (long val : wrongIdsList) {
            this->wrongIdsCount += val;
        }

        std::cout << strId1 << "-" << strId2 << " has " << wrongSize << " invalids IDs : " << std::endl;
        for (int val : wrongIdsList) {
       //     std::cout << "wrong=" << val << std::endl;
        }
   }

   std::cout << "Adding up all the invalid IDs produces " << this->readWrongIdsCount() << std::endl;
}

long Exercise2::readWrongIdsCount() const {
    return this->wrongIdsCount;
}

void Exercise2::doExecute() {
    run("exercises/sample2.txt");
}

Exercise2::~Exercise2() {
    
}