#ifndef QUICK_SELECT_SORT_1_
#define QUICK_SELECT_SORT_1_

#include "InsertionSort.hpp"
#include <string>
#include <vector>
#include <iostream>

// partition for quickselect1
int partition1(std::vector<int>& vec, int left, int right);

// quick select for quickselect1
int quickselectHelper1(std::vector<int>& vec, int left, int right, int k);

void quickSelect1 (const std::string & header, std::vector<int> data);

#endif