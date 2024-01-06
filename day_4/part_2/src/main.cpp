#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "../includes/scratchcards.h"

using namespace std;

int main()
{
    ifstream file;

    vector<string> scratchcards;

    file.open("sample.txt");

    string line;
    while (getline(file, line))
         scratchcards.push_back(line);
    

    file.close();

    size_t totalScratchcards = 0;

    for (size_t i = 0; i <  scratchcards.size(); i++)
        getCopies(scratchcards[i], scratchcards, i, totalScratchcards);

    cout << "TOTAL SCRATCHCARDS: " << totalScratchcards << endl;
    
    return 0;
}

