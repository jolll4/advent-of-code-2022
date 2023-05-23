#include <iostream>
#include <fstream>

void appendNewLetter(std::string* sample, char addedLetter) {
    sample->push_back(addedLetter);

}

void eraseFirstappendNewLetter(std::string* sample, char addedLetter) {
    sample->erase(0,1);
    appendNewLetter(sample, addedLetter);
}

bool checkIfKeysAreUnique(std::string sample, int keySetSize) {
    bool keysAreUnique = true;
    for(unsigned int j = 0; j < keySetSize; j++) {
                for(unsigned int k = 0; k < keySetSize; k++) {
                    if(j != k && sample[j] == sample[k]) {
                        keysAreUnique = false;
                    }
                }
            }
    return keysAreUnique;
}

void printAnswer(std::string sample, int charLocation) {
    std::cout << "The first matching text is " << sample << std::endl;
    std::cout << "which ends at char number " << charLocation+1 << std::endl;
}

void findFirstSetOfUniqueKeys(std::string row, int keySetSize) {
    std::string sample = "";
    for(unsigned int i = 0; i < row.length(); i++) {
        if (i > keySetSize-1) {
            eraseFirstappendNewLetter(&sample, row[i]);
            if(checkIfKeysAreUnique(sample, keySetSize)) {
                printAnswer(sample, i);
                break;
            }
        } else {
            appendNewLetter(&sample, row[i]);
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