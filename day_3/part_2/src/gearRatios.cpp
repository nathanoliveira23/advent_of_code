#include <cctype>
#include <fstream>
#include <cstddef>
#include <cstdint>
#include <utility>
#include "../includes/gearRatios.h"

void getSchematic(char schematic[LINE][COL])
{
    std::ifstream file;
    file.open("input.txt");

    for (size_t i = 0; i < LINE; i++)
        for (size_t j = 0; j < COL; j++)
            file >> schematic[i][j];

    file.close();
}


bool isDotOrDigit(char mat[LINE][COL], size_t line, size_t col)
{
    char ch = mat[line][col];
    
    return ch == DOT || isdigit(ch); 
}

bool isValid(size_t i, size_t j, size_t rows, size_t cols) 
{
    return i >= 0 && i < rows && j >= 0 && j < cols;
}

char getNeighbor(char mat[LINE][COL], size_t i, size_t j)
{
    int dirs[8][2] = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1},
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
    };

    for (size_t k = 0; k < 8; k++) {
        std::size_t di = i + dirs[k][0];
        std::size_t dj = j + dirs[k][1];

        if (!isDotOrDigit(mat, di, dj) && isValid(di, dj, LINE, COL))
            return mat[di][dj];
    }

    return ' ';
}

std::pair<size_t, size_t> getNeighborPosition(char mat[LINE][COL], size_t i, size_t j)
{
    int dirs[8][2] = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1},
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
    };

    for (size_t k = 0; k < 8; k++) {
        std::size_t di = i + dirs[k][0];
        std::size_t dj = j + dirs[k][1];

        if (!isDotOrDigit(mat, di, dj) && isValid(di, dj, LINE, COL))
           return std::make_pair(di, dj); 
    }
    
    return std::make_pair(SIZE_MAX, SIZE_MAX);
}

int sumOfGearsRatios(std::vector<std::pair<int, std::pair<std::size_t, std::size_t>>> gears)
{
    int sum = 0;

    for (std::size_t i = 0; i < gears.size(); i++) {
        for (std::size_t j = i + 1; j < gears.size(); j++) {
            int mult;
            int firstAdjacent = gears[i].first;
            int secondAdjacent = gears[j].first;
            
            std::pair<size_t, size_t> firstCoordAdjacent = std::make_pair(gears[i].second.first, gears[i].second.second);
            std::pair<size_t, size_t> secondCoordAdjacent = std::make_pair(gears[j].second.first, gears[j].second.second);

            if (firstCoordAdjacent.first == secondCoordAdjacent.first && firstCoordAdjacent.second == secondCoordAdjacent.second) {
                mult = firstAdjacent * secondAdjacent;
                sum += mult;
                break;
            }
        }
    }

    return sum;
}
