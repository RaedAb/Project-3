#include "QuickSelect2.hpp"

// partition for quickselect
int partition2(std::vector<int>& vec, int left, int right) {
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

// partition for quickselect2
void quickselectHelper2(std::vector<int>& vec, int left, int right, std::unordered_set<int>& keys) {
    if (right - left + 1 <= 20)
    {
        insertionSort(vec, left, right);
    }
    else if (left <= right) {
        int pivotIndex = partition2(vec, left, right);
        std::unordered_set<int> leftKeys, rightKeys;
        for (auto key : keys) {
            if (key < pivotIndex) leftKeys.insert(key);
            else if (key > pivotIndex) rightKeys.insert(key);
        }
        if (!leftKeys.empty()) quickselectHelper2(vec, left, pivotIndex - 1, leftKeys);
        if (!rightKeys.empty()) quickselectHelper2(vec, pivotIndex + 1, right, rightKeys);
    }
}

void quickSelect2 (const std::string & header, std::vector<int> data)
{
    // quickselect(data, data.begin(), data.end());

    // Get stats
    int n = data.size();

    int min = 0;
    int p25 = (n / 4) - 1;
    int med = (n / 2) - 1;
    int p75 = (3*n / 4) - 1;
    int max = n - 1;

    // put in set
    std::unordered_set<int> keys = {min, p25, med, p75, max};

    quickselectHelper2(data, 0, n - 1, keys);

    std::cout << header << "\n" <<
        "Min: " << data[min] << "\n" <<
        "P25: " << data[p25] << "\n" <<
        "P50: " << data[med] << "\n" <<
        "P75: " << data[p75] << "\n" <<
        "Max: " << data[max] << "\n";
}