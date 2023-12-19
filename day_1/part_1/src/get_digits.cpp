#include "../includes/get_digits.h"

int get_digits(std::string input)
{
    std::string number;
    bool foundFirsDigit = false;

    for (size_t i = 0; i < input.size(); i++) {
        if (std::isdigit(input[i])) {
            if (!foundFirsDigit) {
                number.push_back(input[i]);
                foundFirsDigit = true;
            }
            
            number[1] = input[i];
        }
    }

    return std::stoi(number);
}

