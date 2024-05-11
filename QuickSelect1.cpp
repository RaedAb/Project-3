#include "QuickSelect1.hpp"

// partition for quickselect1
int partition1(std::vector<int>& vec, int left, int right)
{
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
int quickselectHelper1(std::vector<int>& vec, int left, int right, int k)
{
    if (vec.size() <= 20)
    {
        insertionSort(vec, left, right);
    }
    else if (left <= right) {
        int pivotIndex = partition1(vec, left, right);
        if (pivotIndex == k - 1)
            return vec[pivotIndex];
        else if (pivotIndex > k - 1)
            return quickselectHelper1(vec, left, pivotIndex - 1, k);
        else
            return quickselectHelper1(vec, pivotIndex + 1, right, k);
    }
    return -1; // Return -1 if k is out of range
}

void quickSelect1(const std::string& header, std::vector<int> data)
{
    int n = data.size() + 1;

    int med = quickselectHelper1(data, 0, data.size() - 1, n / 2);
    int p25 = quickselectHelper1(data, 0, data.size() / 2, n / 4);
    int p75 = quickselectHelper1(data, (data.size() - 1) / 2, data.size() - 1, 3*n / 4);

    // search for min max
    int min = quickselectHelper1(data, 0, data.size() / 4, 1);
    int max = quickselectHelper1(data, (data.size() - 1) / 2, data.size() - 1, n - 1);

    std::cout << header << "\n" <<
        "Min: " << min << "\n" <<
        "P25: " << p25 << "\n" <<
        "P50: " << med << "\n" <<
        "P75: " << p75 << "\n" <<
        "Max: " << max << "\n";
}

