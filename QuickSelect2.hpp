#ifndef QUICK_SELECT_SORT_2_
#define QUICK_SELECT_SORT_2_

#include "InsertionSort.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

// partition for quickselect
int partition2(std::vector<int>& vec, int left, int right);

// partition for quickselect2
void quickselectHelper2(std::vector<int>& vec, int left, int right, std::unordered_set<int>& keys);

void quickSelect2 (const std::string & header, std::vector<int> data);

#endif