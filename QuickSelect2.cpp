#include "QuickSelect2.hpp"

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

    quickselect(data, 0, n - 1, keys);

    std::cout << header << "\n" <<
        "Min: " << data[min] << "\n" <<
        "P25: " << data[p25] << "\n" <<
        "P50: " << data[med] << "\n" <<
        "P75: " << data[p75] << "\n" <<
        "Max: " << data[max] << "\n";
}