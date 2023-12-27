#include <cctype>
#include <cstddef>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "../includes/gearRatios.h"

using namespace std;

char matrix[LEN][LEN];

int main()
{
    ifstream file;
    file.open("input.txt");

    for (size_t i = 0; i < LEN; i++)
        for (size_t j = 0; j < LEN; j++)
            file >> matrix[i][j];

    file.close();


    string digit;
    vector<string> numbers;
    bool validDigit = false;

    int sum = 0;

    for (size_t i = 0; i < LEN; i++) {
        for (size_t j = 0; j < LEN; j++) {
            char temp = matrix[i][j];

            if (isdigit(temp)) {
                digit.push_back(temp);

                if (getNeighbor(matrix, i, j) != ' ')
                    validDigit = true;
            }
            else {
                if (validDigit) {
                    validDigit = false;
                    numbers.push_back(digit);
                }

                digit.clear();
            }
        }
    }

    for (string num : numbers)
        sum += std::stoi(num);

    std::cout << sum << std::endl;

    return 0;
}
