#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "StdSort.hpp"
#include "QuickSelect1.hpp"
#include "QuickSelect2.hpp"
#include "CountingSort.hpp"

int main()
{
    std::ifstream file("test_input.txt"); // Open input file

    if (!file.is_open())
    {
        std::cerr << "Unable to open file.\n";
        return 1;
    }

    // get the header
    std::string header;
    std::getline(file, header);

    // extract the data
    std::vector<int> data;

    std::string numbers;
    std::getline(file, numbers);

    std::istringstream iss(numbers);
    std::string num;

    while (iss >> num)
    {
        data.push_back(std::stoi(num));
    }

    // stdSort(header, data);
    // std::cout << "\n";
    // quickSelect1(header, data);
    // std::cout << "\n";
    // quickSelect2(header, data);
    // std::cout << "\n";
    countingSort(header, data);
}