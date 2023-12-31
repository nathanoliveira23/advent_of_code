#include <cctype>
#include <cstddef>
#include <string>
#include <vector>
#include <iostream>
#include "../includes/gearRatios.h"

using namespace std;

char schematic[LINE][COL];

int main()
{
    getSchematic(schematic);

    string digit;
    vector<pair<int, pair<size_t, size_t>>> gears;
    bool validDigit = false;
    int sum;

    for (size_t i = 0; i < LINE; i++) {
        for (size_t j = 0; j < COL; j++) {
            char temp = schematic[i][j];
            int x, y;

            if (isdigit(temp)) {
                digit.push_back(temp);

                if (getNeighbor(schematic, i, j) == SYMBOL) {
                    validDigit = true;
                    pair<size_t, size_t> posSymbol = getNeighborPosition(schematic, i, j);
                    x = posSymbol.first;
                    y = posSymbol.second;
                }
            }
            else {
                if (validDigit) {
                    validDigit = false;
                    gears.emplace_back(stoi(digit), make_pair(x, y));
                }

                digit.clear();
            }
        }
    }

    sum = sumOfGearsRatios(gears);

    cout << "Soma: " << sum << endl;

    return 0;
}
