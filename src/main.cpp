#include <iostream>
#include "./include/DataManip/DataManip.h"

int main() {
    DataFrame df = DataFrame("/home/krishnachandran/myfiles/dev/DataScienceAlgorithms/datasets/starbucks.csv");   
    df.head(10);
}
