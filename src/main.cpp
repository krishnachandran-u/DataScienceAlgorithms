#include <iostream>
#include "./include/DataManip/DataManip.h"

int main() {
    DataFrame df = DataFrame("/home/krishnachandran/myfiles/dev/DataScienceAlgorithms/datasets/starbucks.csv");   
    df.head(10);
    DataFrame train = df.trainTestSplit(0.8).first; 
    DataFrame test = df.trainTestSplit(0.2).second;
}
