#include "./../../include/DataManip/DataManip.h"
#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <sstream>
#include <algorithm>

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

std::pair<DataFrame, DataFrame> DataFrame::trainTestSplit(float trainFraction) {
    int n = data.size();
    int trainSize = (int)(trainFraction * n);
    DataFrame train;
    DataFrame test;
    for(int i = 0; i < trainSize; i++) {
        train.pushBack(data[i]);
    }
    for(int i = trainSize; i < n; i++) {
        test.pushBack(data[i]);
    }
    return std::make_pair(train, test);
}

void DataFrame::pushBack(const std::vector<std::string>& row) {
    data.push_back(row);
    return;  
}

DataFrame DataFrame::stripPredictor() {
    DataFrame strippedDf;
    for(int i = 0; i < (int)data.size(); i++) {
        std::vector<std::string> row;
        for(int j = 0; j < (int)data[i].size() - 1; j++) {
            row.push_back(data[i][j]);
        }
        strippedDf.pushBack(row);
    }
    return strippedDf;
}

DataFrame DataFrame::stripTarget() {
    DataFrame strippedDf;
    for(int i = 0; i < (int)data.size(); i++) {
        std::vector<std::string> row;
        row.push_back(data[i][(int)data[i].size() - 1]);
        strippedDf.pushBack(row);
    }
    return strippedDf;
}

void DataFrame::sort() {
    std::sort(data.begin(), data.end());
}
