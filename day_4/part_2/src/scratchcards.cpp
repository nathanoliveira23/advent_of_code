#include "../includes/scratchcards.h"

void getCopies(std::string& scratchcard, std::vector<std::string> scratchcards, size_t index, size_t& acc) 
{
    size_t matches = getMatches(scratchcard);
    acc++;

    if (matches == 0)
        return;

    for (size_t i = 1; i <= matches; i++)
        getCopies(scratchcards[index + i], scratchcards, index + i, acc);
}

int getMatches(std::string& card)
{
    size_t initPos, delimiter;

    initPos = card.find(':');
    delimiter = card.find('|');
    
    std::string number;
    std::vector<std::string> setA, setB;
    bool isValidNumber = false;

    for (size_t i = initPos; i < card.size(); i++) {
        char tempDigit = card[i];

        if (isdigit(tempDigit)) {
            number.push_back(tempDigit);
            isValidNumber = true;

            if (i == card.size() - 1)
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

    return getIntersectionSize(setA, setB);
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
