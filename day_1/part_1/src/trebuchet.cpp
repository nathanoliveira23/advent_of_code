#include <iostream>
#include <fstream>
#include "../includes/get_digits.h"

int main(void)
{
    std::ifstream file("input.txt");
    std::string word;
    int number, sum = 0;

    if (!file.is_open())
        std::cout << "Erro ao abrir o arquivo\n";

    while (std::getline(file, word)) {
        number = get_digits(word);
        sum = sum + number;
    }

    file.close();

    std::cout << sum << std::endl;

    return 0;
}

