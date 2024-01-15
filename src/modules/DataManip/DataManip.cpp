#include "./../include/DataManip.h"
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
        for(int j = 0; j < data[i].size(); j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void DataFrame::tail(int n) {
    int cnt = 0;
    for(int i = data.size() - 1; i >= 0 && cnt < n; i--, cnt++) {
        for(int j = 0; j < data[i].size(); j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << "\n";
    }
}
