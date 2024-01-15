#include <iostream>
#include "./include/DataManip/DataManip.h"

int main() {
    DataFrame df = DataFrame("./../datasets/starbucks.csv");   
    df.head(10);
}
