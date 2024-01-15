#include "./../include/DataManip.h"
#include <iostream>
#include <vector>
#include <utility>
#include <fstream>

std::vector<std::string> DataFrame::split(const std::vector<string>& s, char delimiter) {
    std::vector<std::string> row;
    std::stringstream ss(s);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        row.push_back(token);
    }
    return row;  
}

DataFrame::DataFrame(const std::string& filename) { 
    try {
        std::ifstream file(filename);
    }
    catch (std::ifstream::failure e) {
        std::cerr << "Exception opening/reading file";
    }
    std::string line;
    while(std::getline(file, line)) {
        std::vector<std::string> row = split(line, ',');
        data.push_back(row);
    }
}
