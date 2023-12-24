#include <cstddef>
#include <string>
#include <unordered_map>
#include "../includes/cubeConundrum.h"

int charToInt(char ch)
{
    return std::isdigit(ch) ? ch - 48 : -1;
}

int powerSet(std::string str)
{
    std::string txt;
    std::unordered_map<std::string, int> colors;
    size_t j, pos;
    int digit, result;
    bool haveAnotherDigit = false;

    pos = str.find(":");
    str.erase(0, pos + 2);

    for (size_t i = 0; i < str.size(); i++) {
        txt.clear();

        if (isdigit(str[i]) && haveAnotherDigit) {
            haveAnotherDigit = false;
            continue;
        }

        if (isdigit(str[i])) {
            digit = charToInt(str[i]);
            
            if (isdigit(str[i + 1])) {
                digit = (digit * 10) + charToInt(str[i + 1]);
                haveAnotherDigit = true;
            }

            continue;
        }
    
        j = 2;
        while (j < 5 && str.size() - i) {
            txt = str.substr(i, j + 1);
            
            if (txt == "red") {
                if (digit > colors[txt])
                    colors[txt] = digit;
            }
            else if (txt == "blue") {
                if (digit > colors[txt])
                    colors[txt] = digit;
            }
            else if (txt == "green") {
                if (digit > colors[txt])
                    colors[txt] = digit;
            }

            j++;
        }
    }

    result = 1;

    for (auto color : colors)
        result *= color.second;

    return result;
}
