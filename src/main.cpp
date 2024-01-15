#include <iostream>
#include "./include/DataManip/DataManip.h"

int main() {
    DataFrame df = DataFrame("./../datasets/magic04.data");   
    df.head(10);
}
