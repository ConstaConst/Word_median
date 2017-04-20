#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

int countKey(std::string &key, std::ifstream &file) {
    std::string curStr;
    int counter = 0;

    while (file >> curStr) {
        if(curStr == key) {
            counter++;
        }
    }
    return counter;
}

std::vector<int> searchKey(std::string &key, char** &filesNames, int numberFiles) {
    std::ifstream file;
    std::vector<int> keysInFiles(numberFiles - 2);


    for(int i = 2, j = 0; i < numberFiles; i++) {
        file.open(filesNames[i], std::ios::in);
        if(file) {
            keysInFiles[j++] = countKey(key, file);
        }
        else {
            std::cout << "File "<< filesNames[i] <<" hasn't been opened. It don't count." << std::endl;
            keysInFiles.resize(keysInFiles.size() - 1);
        }
        file.close();
    }

    return keysInFiles;
}

int searchMedian(std::vector<int> &keysInFiles) {
    std::sort(keysInFiles.begin(), keysInFiles.end());

    return keysInFiles[(keysInFiles.size() - 1) / 2];
}

