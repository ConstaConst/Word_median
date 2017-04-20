#include <fstream>
#include <vector>

#ifndef HW8_MEDIAN_CPP_SEARCHMEDIAN_H
#define HW8_MEDIAN_CPP_SEARCHMEDIAN_H

int countKey(std::string &key, std::ifstream &file);
std::vector<int> searchKey(std::string &key, char** &filesNames, int numberFiles);
int searchMedian(std::vector<int> &keysInFiles);

#endif //HW8_MEDIAN_CPP_SEARCHMEDIAN_H
