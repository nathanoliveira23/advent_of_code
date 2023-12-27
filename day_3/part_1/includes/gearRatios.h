#pragma once

#include <cstddef>

#define DOT '.'
#define LEN 140

void printMatrix(char [LEN][LEN]);
bool isDotOrDigit(char [LEN][LEN], size_t, size_t);
bool isValid(size_t, size_t, size_t, size_t);
char getNeighbor(char [LEN][LEN], size_t, size_t);
