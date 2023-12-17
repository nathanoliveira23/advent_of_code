#include "../includes/get_digits.h"

int get_digits(std::string input)
{
    std::string number;
    size_t index = 0;

    // Get first digit
    for (size_t i = 0; i < input.size(); i++) {
        if (std::isdigit(input[i])) {
            number.push_back(input[i]);
            index = i;
            break;
        }
    }

    // Get second digit
    for (size_t i = index; i < input.size(); i++)
        if (std::isdigit(input[i]))
            number[1] = input[i];

    return std::stoi(number);
}

