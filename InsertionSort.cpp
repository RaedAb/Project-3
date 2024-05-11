#include "InsertionSort.hpp"

// Insertion Sort for small partitions
void insertionSort(std::vector<int>& vec, int left, int right)
{
    for (int i = left + 1; i <= right; ++i) {
        int key = vec[i];
        int j = i - 1;
        while (j >= left && vec[j] > key) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = key;
    }
}