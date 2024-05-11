#include "CountingSort.hpp"

void countingSort (const std::string & header, std::vector<int> data)
{
    std::unordered_map<int, int> vals;

    // put data into hash map
    for (const auto& i : data)
    {
        auto it = vals.find(i);

        if (it != vals.end())
        {
            it->second++;
        }
        else
        {
            vals[i] = 1;
        }
    }
    
    std::vector<std::pair<int, int>> vec;

    // put key value pairs into vector
    for (auto it = vals.begin(); it != vals.end(); ++it)
    {
        vec.push_back(std::make_pair(it->first, it->second));
    }

    // sort
    std::sort(vec.begin(), vec.end());

    int n = data.size();

    int p25_index = (n / 4);
    int med_index = (n / 2);
    int p75_index = (3 * n / 4);

    int min = vec.front().first;
    int p25 = 0;
    int med = 0;
    int p75 = 0;
    int max = vec.back().first;

    int count = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        count += it->second;

        // Update p25, med, p75 if they haven't been updated yet
        if (p25 == 0 && count >= p25_index) {
            p25 = it->first;
        }
        if (med == 0 && count >= med_index) {
            med = it->first;
        }
        if (p75 == 0 && count >= p75_index) {
            p75 = it->first;
        }
    }

    std::cout << header << "\n" <<
        "Min: " << min << "\n" <<
        "P25: " << p25 << "\n" <<
        "P50: " << med << "\n" <<
        "P75: " << p75 << "\n" <<
        "Max: " << max << "\n" <<
        "Unique: " << vals.size();
}