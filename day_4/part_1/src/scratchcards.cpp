#include "../includes/scratchcards.h"

int getPoints(int n)
{
    if (n == 0 || n == 1 || n == 2)
        return n;

    return 2 * getPoints(n - 1);
}

int getIntersectionSize(std::vector<std::string> setA, std::vector<std::string> setB)
{
    int count = 0;

    for (size_t i = 0; i < setA.size(); i++) {
        for (size_t j = 0; j < setB.size(); j++) {
            if (setA[i] == setB[j]) {
                count++;
                break;
            }
        }
    }

    return count;
}
