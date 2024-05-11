#include "QuickSelect.hpp"

// Insertion Sort for small partitions
void insertionSort(std::vector<int>& vec, int left, int right) {
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

// partition for quickselect1
int partition(std::vector<int>& vec, int left, int right) {
    int pivot = vec[right];
    int i = left - 1;

    for (int j = left; j < right; ++j) {
        if (vec[j] <= pivot) {
            ++i;
            std::swap(vec[i], vec[j]);
        }
    }

    std::swap(vec[i + 1], vec[right]);
    return i + 1;
}

// quick select for quickselect1
int quickselect(std::vector<int>& vec, int left, int right, int k) {
    if (right - left + 1 <= 20)
    {
        insertionSort(vec, left, right);
    }
    else if (left <= right) {
        int pivotIndex = partition(vec, left, right);
        if (pivotIndex == k - 1)
            return vec[pivotIndex];
        else if (pivotIndex > k - 1)
            return quickselect(vec, left, pivotIndex - 1, k);
        else
            return quickselect(vec, pivotIndex + 1, right, k);
    }
    return -1; // Return -1 if k is out of range
}

// partition for quickselect2
void quickselect(std::vector<int>& vec, int left, int right, std::unordered_set<int>& keys) {
    if (right - left + 1 <= 20)
    {
        insertionSort(vec, left, right);
    }
    else if (left <= right) {
        int pivotIndex = partition(vec, left, right);
        std::unordered_set<int> leftKeys, rightKeys;
        for (auto key : keys) {
            if (key < pivotIndex) leftKeys.insert(key);
            else if (key > pivotIndex) rightKeys.insert(key);
        }
        if (!leftKeys.empty()) quickselect(vec, left, pivotIndex - 1, leftKeys);
        if (!rightKeys.empty()) quickselect(vec, pivotIndex + 1, right, rightKeys);
    }
}