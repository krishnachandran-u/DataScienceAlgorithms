#include <iostream>
#include "./include/DataManip/DataManip.h"
#include "./include/LinearRegression/SimpleLinearRegression.h"
#include "./include/Plot/Plot.h"

int main() {
    DataFrame df = DataFrame("/home/krishnachandran/myfiles/dev/DataScienceAlgorithms/datasets/starbucks.csv");   
    df.head(10);
    DataFrame train = df.trainTestSplit(0.8).first; 
    DataFrame test = df.trainTestSplit(0.8).second;

    trainPredictor = df.stripPredictor(train);
    trainTarget = df.stripTarget(train);

    SimpleLinearRegression slr = SimpleLinearRegression(trainPredictor, trainTarget);

    slr.printCoefficients();
}
