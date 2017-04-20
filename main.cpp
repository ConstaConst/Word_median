#include "SearchMedian.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        try {
            throw std::invalid_argument("ERROR! Too few arguments, expected 3 and more.\n");
        }
        catch (std::invalid_argument err) {
            std::cout <<  err.what();
            return EXIT_FAILURE;
        }
    }

    std::string key(argv[1]);
    std::vector<int> keysInFiles;
    try {
        keysInFiles = searchKey(key, argv, argc);
    }
    catch (std::bad_alloc) {
        std::cout << "ERROR! No memory.\n";
        return EXIT_FAILURE;
    }

    std::cout << "median = " << searchMedian(keysInFiles) << std::endl;
    for(int i = 0; i < keysInFiles.size(); i++){
        std::cout << keysInFiles[i] << std::endl;
    }
    return 0;
}
