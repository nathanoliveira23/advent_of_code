#pragma once

#include <cstddef>
#include <utility>
#include <vector>

#define DOT     '.'
#define SYMBOL  '*'
#define LINE    140
#define COL     140

void getSchematic(char [LINE][COL]);
void printMatrix(char [LINE][COL]);
bool isDotOrDigit(char [LINE][COL], size_t, size_t);
bool isValid(size_t, size_t, size_t, size_t);
char getNeighbor(char [LINE][COL], size_t, size_t);
std::pair<size_t, size_t> getNeighborPosition(char [LINE][COL], size_t, size_t);
int sumOfGearsRatios(std::vector<std::pair<int, std::pair<std::size_t, std::size_t>>>);
