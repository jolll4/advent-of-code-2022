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

void findFirstSetOfUniqueKeys(std::string textInput, unsigned int keySetSize) {
    std::string textSample = "";
    for(unsigned int i = 0; i < textInput.length(); i++) {
        if (i >= keySetSize) {
            eraseFirstappendNewLetter(&textSample, textInput[i]);
            if(checkIfKeysAreUnique(textSample, keySetSize)) {
                printAnswer(textSample, i+1);
                break;
            }
        } else {
            appendNewLetter(&textSample, textInput[i]);
        }
    }
}

std::string readInputFileContent(std::string fileName) {
    std::fstream file;
    std::string rowOfText;

    file.open(fileName);
    getline(file, rowOfText);
    file.close();
    return rowOfText;
}

int main() {
    std::string rowOfText = readInputFileContent("day6-input.txt");
    findFirstSetOfUniqueKeys(rowOfText, 4);
    findFirstSetOfUniqueKeys(rowOfText, 14);

    return 0;
}