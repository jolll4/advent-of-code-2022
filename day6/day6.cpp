#include <iostream>
#include <fstream>

int searcher(std::string row, int n) {
    std::string sample = "";
    for(unsigned int i = 0; i < row.length(); i++) {
        if (i > n-1) {
            sample.erase(0,1);
            sample.push_back(row[i]);
            bool duplicateFound = false;
            for(unsigned int j = 0; j < n; j++) {
                for(unsigned int k = 0; k < n; k++) {
                    if(j != k && sample[j] == sample[k]) {
                        duplicateFound = true;
                    }
                }
            }
            if(!duplicateFound) {
                std::cout << sample << "\n";
                std::cout << i+1 << "\n";
                break;
            }
        } else {
            sample.push_back(row[i]);
        }
    }
    return 0;
}

int main() {
    std::fstream file;
    std::string row;

    file.open("day6-input.txt");
    getline(file, row);
    file.close();

    searcher(row, 4);
    searcher(row, 14);

    return 0;
}