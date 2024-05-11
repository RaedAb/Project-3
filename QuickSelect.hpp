#ifndef QUICK_SORT_HPP_
#define QUICK_SORT_HPP_

#include <vector>
#include <algorithm>
#include <unordered_set>

// Insertion Sort for small partitions
void insertionSort(std::vector<int>& vec, int left, int right);

// partition for quickselect1
int partition(std::vector<int>& vec, int left, int right);

// quick select for quickselect1
int quickselect(std::vector<int>& vec, int left, int right, int k);

// partition for quickselect2
void quickselect(std::vector<int>& vec, int left, int right, std::unordered_set<int>& keys);

#endif