#include "./../../include/DataManip/DataManip.h"
#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <sstream>

std::vector<std::string> DataFrame::split(const std::string& s, char delimiter) {
    std::vector<std::string> row;
    std::stringstream ss(s);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        row.push_back(token);
    }
    return row;  
}

DataFrame::DataFrame() {}

DataFrame::DataFrame(const std::string& filename) { 
    std::ifstream file(filename);
    if(!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        throw std::ifstream::failure("Error opening file");
    }
    std::string line;
    while(std::getline(file, line)) {
        std::vector<std::string> row = split(line, ',');
        data.push_back(row);
    }

    file.close();
}

void DataFrame::head(int n) {
    for(int i = 0; i < std::min(n, (int)data.size()); i++) {
        for(int j = 0; j < (int)data[i].size(); j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << "\n";
    }
    return;
}

void DataFrame::tail(int n) {
    int cnt = 0;
    for(int i = data.size() - 1; i >= 0 && cnt < n; i--, cnt++) {
        for(int j = 0; j < (int)data[i].size(); j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << "\n";
    }
    return;
}

std::pair<DataFrame, DataFrame> DataFrame::trainTestSplit(float testFraction) {
    int testSize = (int)(data.size() * testFraction);
    int trainSize = data.size() - testSize;
    DataFrame train, test;
    for(int i = 0; i < trainSize; i++) {
        train.data.push_back(data[i]);
    }
    for(int i = trainSize; i < (int)data.size(); i++) {
        test.data.push_back(data[i]);
    }
    return std::make_pair(train, test);
}
