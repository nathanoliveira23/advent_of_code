#include <cstddef>
#include "../includes/cubeConundrum.h"


int charToInt(char ch)
{
    return std::isdigit(ch) ? ch - 48 : 0;
}

int getGameId(std::string str) 
{
    size_t j = 0;
    char firstDigit, secondDigit, thirdDigit;

    while (str[j] != ':') {
        firstDigit = charToInt(str[j]);
        secondDigit = charToInt(str[j + 1]);
        thirdDigit = charToInt(str[j + 2]);

        if (std::isdigit(str[j]) && std::isdigit(str[j + 1]) && std::isdigit(str[j + 2])) {
            return firstDigit * 100 + secondDigit * 10 + thirdDigit;
        }
        else if (std::isdigit(str[j]) && std::isdigit(str[j + 1])) {
            return firstDigit * 10 + secondDigit;
        }
        else if (std::isdigit(str[j]))
            return firstDigit;

        j++;
    }

    return -1;
}

int getValidGameId(std::string str)
{
    int id = getGameId(str);

    std::string txt;
    int digit;
    size_t j;

    bool haveAnotherDigit = false;
    bool redValid = true, greenValid = true, blueValid = true;
    for (size_t i = 8; i < str.size(); i++) {
        txt.clear();

        if (std::isdigit(str[i]) && haveAnotherDigit) {
            haveAnotherDigit = false;
            continue;
        }

        if (std::isdigit(str[i])) {
            digit = charToInt(str[i]);
            
            if (std::isdigit(str[i + 1])) {
                digit *= 10;
                digit += charToInt(str[i + 1]);
                haveAnotherDigit = true;
            }

            continue; 
        }

        j = 2;
        while (j < 5 && j < str.size() - i) {
            txt = str.substr(i, j + 1); 

            if (txt == "red" && digit > 12)
                redValid = false;
            else if (txt == "green" && digit > 13)
                greenValid = false;
            else if (txt == "blue" && digit > 14)
                blueValid = false;

            j++;
        }
    }

    if (redValid && greenValid && blueValid)
        return id;
    else
        return 0;
}
