#include <iostream>
#include <fstream>

void appendNewLetter(std::string* textSample, char addedLetter) {
    textSample->push_back(addedLetter);
}

void eraseFirstappendNewLetter(std::string* textSample, char addedLetter) {
    textSample->erase(0,1);
    appendNewLetter(textSample, addedLetter);
}

bool checkIfKeysAreUnique(std::string textSample, unsigned int keySetSize) {
    bool keysAreUnique = true;
    for(unsigned int j = 0; j < keySetSize; j++) {
        for(unsigned int k = 0; k < keySetSize; k++) {
            if(j != k && textSample[j] == textSample[k]) {
                keysAreUnique = false;
            }
        }
    }
    return keysAreUnique;
}

void printAnswer(std::string textSample, unsigned int charLocation) {
    std::cout << "The first matching text is " << textSample << std::endl;
    std::cout << "which ends at char number " << charLocation << std::endl;
}

void findFirstSetOfUniqueKeys(std::string row, unsigned int keySetSize) {
    std::string textSample = "";
    for(unsigned int i = 0; i < row.length(); i++) {
        if (i > keySetSize-1) {
            eraseFirstappendNewLetter(&textSample, row[i]);
            if(checkIfKeysAreUnique(textSample, keySetSize)) {
                printAnswer(textSample, i+1);
                break;
            }
        } else {
            appendNewLetter(&textSample, row[i]);
        }
    }
}

std::string readInputFileContent() {
    std::fstream file;
    std::string row;

    file.open("day6-input.txt");
    getline(file, row);
    file.close();
    return row;
}

int main() {
    std::string row = readInputFileContent();
    findFirstSetOfUniqueKeys(row, 4);
    findFirstSetOfUniqueKeys(row, 14);

    return 0;
}