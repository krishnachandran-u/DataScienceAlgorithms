#ifndef DATAMANIP_H
#define DATAMANIP_H

#include <iostream>
#include <vector>
#include <utility>

class DataFrame {
    private:
        std::vector<std::vector<std::string>> data;
        std::vector<std::string> split(const std::string& s, char delimiter);
    public: 
        DataFrame();
        DataFrame(const std::string& filename);
        void pushBack(const std::vector<std::string>& row);
        void head(int n);
        void tail(int n);
        std::pair<DataFrame, DataFrame> trainTestSplit(float trainFraction);
        DataFrame stripPredictor(Dataframe df);
};

#endif // DATAMANIP_H
