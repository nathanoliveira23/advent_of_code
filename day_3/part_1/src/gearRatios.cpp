#include <cctype>
#include <string>
#include "../includes/gearRatios.h"

bool isDotOrDigit(char mat[LEN][LEN], size_t line, size_t col)
{
    char ch = mat[line][col];
    
    return ch == DOT || isdigit(ch); 
}

bool isValid(size_t i, size_t j, size_t rows, size_t cols) 
{
    return i >= 0 && i < rows && j >= 0 && j < cols;
}

char getNeighbor(char mat[LEN][LEN], size_t i, size_t j)
{
    int dirs[8][2] = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1},
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
    };

    for (size_t k = 0; k < 8; k++) {
        int di = i + dirs[k][0];
        int dj = j + dirs[k][1];

        if (!isDotOrDigit(mat, di, dj) && isValid(di, dj, LEN, LEN))
            return mat[di][dj];
    }

    return ' ';
}
