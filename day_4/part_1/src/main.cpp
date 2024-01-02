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
    file.open("input.txt");

    string line;
    int totalPoints = 0;
    while (getline(file, line)) {
        size_t initPos, delimiter;

        initPos = line.find(':');
        delimiter = line.find('|');
        
        string number;
        vector<string> setA, setB;
        bool isValidNumber = false;

        for (size_t i = initPos; i < line.size(); i++) {
            char tempDigit = line[i];

            if (isdigit(tempDigit)) {
                number.push_back(tempDigit);
                isValidNumber = true;

                if (i == line.size() - 1)
                    setB.push_back(number);
            } 
            else {
                if (isValidNumber) {
                    i < delimiter ? setA.push_back(number) : setB.push_back(number);

                    number.clear();
                    isValidNumber = false;
                }
            }
        }
        
        int intersectLen = getIntersectionSize(setA, setB);
        int points = getPoints(intersectLen);

        totalPoints += points;
    }

    file.close();

    cout << totalPoints << endl;

    return 0;
}

