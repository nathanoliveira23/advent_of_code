#include <fstream>
#include <iostream>
#include <string>
#include "../includes/cubeConundrum.h"

int main(void)
{
    std::ifstream file;
    file.open("input.txt");
    int id, sum = 0;

    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo.\n";
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (getline(file, line)) {
        id = getValidGameId(line);
        sum += id;
    }

    file.close();

    std::cout << sum << std::endl;

    return 0;
}
