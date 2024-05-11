#include "QuickSelect1.hpp"

void quickSelect1 (const std::string & header, std::vector<int> data)
{
    int n = data.size() + 1;

    int med = quickselect(data, 0, data.size() - 1, n / 2);
    int p25 = quickselect(data, 0, data.size() / 2, n / 4);
    int p75 = quickselect(data, (data.size() - 1) / 2, data.size() - 1, 3*n / 4);

    // search for min max
    int min = quickselect(data, 0, data.size() / 4, 1);
    int max = quickselect(data, (data.size() - 1) / 2, data.size() - 1, n - 1);

    std::cout << header << "\n" <<
        "Min: " << min << "\n" <<
        "P25: " << p25 << "\n" <<
        "P50: " << med << "\n" <<
        "P75: " << p75 << "\n" <<
        "Max: " << max << "\n";
}