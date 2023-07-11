#include <iostream>
#include <fstream>
#include <string>
#include <vector>    

using namespace std;

vector<string> readInputFileContent(string fileName) {
    fstream file;
    string rowOfText;
    vector<string> mapOfTrees;

    file.open(fileName);
    getline(file, rowOfText);
    mapOfTrees.push_back(rowOfText);
    while(getline(file, rowOfText)) {
        mapOfTrees.push_back(rowOfText);
    }
    file.close();
    return mapOfTrees;
}

int countVertical(vector<string> mapOfTrees, unsigned int columnCount) {
    int verticalSum = 0;
    for(unsigned int rowNumber = 1; rowNumber < mapOfTrees.size(); rowNumber++) {
        int highestInColumn = 0;
        for(unsigned int columnNumber = 0; columnNumber < columnCount; columnNumber++) {
            if(mapOfTrees[rowNumber][columnNumber] > highestInColumn) {
                highestInColumn = mapOfTrees[rowNumber][columnNumber];
                verticalSum++;
            }
        }
    }
    return verticalSum;
}

int countHorizontal(vector<string> mapOfTrees, unsigned int columnCount) {
    int horizontalSum = 0;
    for(unsigned int columnNumber = 1; columnNumber < columnCount; columnNumber++) {
        int highestInRow = 0;
        for(unsigned int rowNumber = 0; rowNumber < mapOfTrees.size(); rowNumber++) {
            if(mapOfTrees[rowNumber][columnNumber] > highestInRow) {
                highestInRow = mapOfTrees[rowNumber][columnNumber];
                horizontalSum++;
            }
        }
    }
    return horizontalSum;
}

int countVisibleTrees(vector<string> mapOfTrees) {
    unsigned int columnCount = mapOfTrees[0].size();
    int verticalSum = countVertical(mapOfTrees, columnCount);
    int horizontalSum = countHorizontal(mapOfTrees, columnCount);
    cout << verticalSum << " " << horizontalSum << " " << endl;
    return verticalSum + horizontalSum + 4;
}

int main() {
    vector<string> mapOfTrees = readInputFileContent("day8-input.txt");
    int visibleTrees = countVisibleTrees(mapOfTrees);
    cout << visibleTrees << endl;
    return 0;
}