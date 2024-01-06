#pragma once

#include <cstddef>
#include <string>
#include <vector>
#include <unordered_map>

void getCopies(std::string&, std::vector<std::string>, size_t, size_t&);
void printMemo();
int getMatches(std::string&);
int getIntersectionSize(std::vector<std::string>, std::vector<std::string>);
