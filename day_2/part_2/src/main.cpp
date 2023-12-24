#include <fstream>
#include <iostream>
#include <string>
#include "../includes/cubeConundrum.h"

using namespace std;

int main(void)
{
    std::ifstream file;
    file.open("input.txt");

    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo.\n";
        exit(EXIT_FAILURE);
    }

    int sum = 0;
    std::string line;
    while (getline(file, line)) {
        sum += powerSet(line);
    }

    file.close();

    cout << sum << endl;

    return 0;
}
