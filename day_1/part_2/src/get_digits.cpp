#include "../includes/get_digits.h"

int get_digits(std::string str) 
{
    std::string txt;
    char digit[3] = { 0 };
    bool foundFirstDigit = false;

    for (size_t i = 0; i < str.size(); i++) {
        txt.clear();

        if (std::isdigit(str[i])) {
            if (!foundFirstDigit) {
                digit[0] = str[i];
                foundFirstDigit = true;
            }

            digit[1] = str[i];
            continue;
        }

        for (size_t j = 1; j < str.size(); j++) {
            txt = str.substr(i, j);

            if (txt.size() > 5)
                break;

            if (numbers.count(txt) > 0) {
                if (!foundFirstDigit) {
                    digit[0] = numbers[txt];
                    foundFirstDigit = true;
                }

                digit[1] = numbers[txt];
                break;
            }
        }
    }
    
    return atoi(digit);
}
