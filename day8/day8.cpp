#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

vector<int> convertRowToIntVector(string inputRow) {
    vector<int> outputRow;
    for(unsigned int i = 0; i < inputRow.size(); i++) {
        outputRow.push_back(inputRow[i] - 48);
    }
    return outputRow;
}

vector<vector<int>> readInputFileContent(string fileName) {
    fstream file;
    string rowOfText;
    vector<vector<int>> mapOfTrees;

    file.open(fileName);
    getline(file, rowOfText);
    mapOfTrees.push_back(convertRowToIntVector(rowOfText));
    while(getline(file, rowOfText)) {
        mapOfTrees.push_back(convertRowToIntVector(rowOfText));
    }
    file.close();
    return mapOfTrees;
}

vector<vector<int>> countVertical(vector<vector<int>> mapOfTrees, vector<vector<int>> visibleTrees, unsigned int columnCount) {
    for(unsigned int rowNumber = 0; rowNumber < mapOfTrees.size(); rowNumber++) {
        int highestInColumn = -1;
        for(unsigned int columnNumber = 0; columnNumber < columnCount; columnNumber++) {
            if(mapOfTrees[rowNumber][columnNumber] > highestInColumn) {
                highestInColumn = mapOfTrees[rowNumber][columnNumber];
                visibleTrees[rowNumber][columnNumber] = 1;
            }
        }
    }
    for(unsigned int rowNumber = mapOfTrees.size()-1; rowNumber > 0; rowNumber--) {
        int highestInColumn = -1;
        for(unsigned int columnNumber = columnCount-1; columnNumber > 0; columnNumber--) {
            if(mapOfTrees[rowNumber][columnNumber] > highestInColumn) {
                highestInColumn = mapOfTrees[rowNumber][columnNumber];
                visibleTrees[rowNumber][columnNumber] = 1;
            }
        }
    }
    return visibleTrees;
}

vector<vector<int>> countHorizontal(vector<vector<int>> mapOfTrees, vector<vector<int>> visibleTrees, unsigned int columnCount) {
    for(unsigned int columnNumber = 0; columnNumber < columnCount; columnNumber++) {
        int highestInRow = -1;
        for(unsigned int rowNumber = 0; rowNumber < mapOfTrees.size(); rowNumber++) {
            if(mapOfTrees[rowNumber][columnNumber] > highestInRow) {
                highestInRow = mapOfTrees[rowNumber][columnNumber];
                visibleTrees[rowNumber][columnNumber] = 1;
            }
        }
    }
    for(unsigned int columnNumber = columnCount-1; columnNumber > 0; columnNumber--) {
        int highestInRow = -1;
        for(unsigned int rowNumber = mapOfTrees.size()-1; rowNumber > 0; rowNumber--) {
            if(mapOfTrees[rowNumber][columnNumber] > highestInRow) {
                highestInRow = mapOfTrees[rowNumber][columnNumber];
                visibleTrees[rowNumber][columnNumber] = 1;
            }
        }
    }
    return visibleTrees;
}

vector<vector<int>> createEmptyForest(int length, int height) {
    vector<vector<int>> emptyForest;
    vector<int> emptyRow;
    for(unsigned int i = 0; i < length; i++) {
        emptyRow.push_back(0);
    }
    for(unsigned int i = 0; i < height; i++) {
        emptyForest.push_back(emptyRow);
    }
    return emptyForest;
}

int findVisibleTrees(vector<vector<int>> visibleTrees) {
    int sum = 0;
    for(unsigned int rowNumber = 0; rowNumber < visibleTrees.size(); rowNumber++) {
        for(unsigned int columnNumber = 0; columnNumber < visibleTrees[0].size(); columnNumber++) {
            if(visibleTrees[rowNumber][columnNumber] > 0) {
                sum++;
                cout << 1;
            } else {
                cout << 0;
            }
        }
        cout << endl;
    }
    return sum;
}

int countVisibleTrees(vector<vector<int>> mapOfTrees) {
    unsigned int columnCount = mapOfTrees[0].size();
    vector<vector<int>> visibleTrees = createEmptyForest(columnCount, mapOfTrees.size());
    visibleTrees = countVertical(mapOfTrees, visibleTrees, columnCount);
    visibleTrees = countHorizontal(mapOfTrees, visibleTrees, columnCount);
    return findVisibleTrees(visibleTrees);
}

int main() {
    vector<vector<int>> mapOfTrees = readInputFileContent("day8-input.txt");
    int visibleTreesCount = countVisibleTrees(mapOfTrees);
    cout << visibleTreesCount << endl;
    return 0;
}