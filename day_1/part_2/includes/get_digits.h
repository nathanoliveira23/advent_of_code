#pragma once

#include <string>
#include <unordered_map>


static std::unordered_map<std::string, char> numbers = {
    {"nine",    '9'},
    {"eight",   '8'},
    {"seven",   '7'},
    {"six",     '6'},
    {"five",    '5'},
    {"four",    '4'},
    {"three",   '3'},
    {"two",     '2'},
    {"one",     '1'}
};

int get_digits(std::string);
