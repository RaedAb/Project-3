#include "StdSort.hpp"

void stdSort (const std::string & header, std::vector<int> data)
{
    std::sort(data.begin(), data.end());

    // Get stats
    int n = data.size() + 1;

    int min = data.front();
    int p25 = data[n / 4 - 1];
    int med = data[n / 2 - 1];
    int p75 = data[3 * n / 4 - 1];
    int max = data.back();

    std::cout << header << "\n" <<
        "Min: " << min << "\n" <<
        "P25: " << p25 << "\n" <<
        "P50: " << med << "\n" <<
        "P75: " << p75 << "\n" <<
        "Max: " << max << "\n";
}