#include <iostream>
#include "./include/DataManip/DataManip.h"
#include "./include/LinearRegression/SimpleLinearRegression.h"
#include "./include/Plot/Plot.h"

int main() {
    DataFrame df = DataFrame("/home/krishnachandran/myfiles/dev/DataScienceAlgorithms/datasets/test.csv");   
    df.head(10);
    DataFrame train = df.trainTestSplit(0.8).first; 
    DataFrame test = df.trainTestSplit(0.8).second;

    DataFrame trainPredictor = train.stripPredictor();
    DataFrame trainTarget = train.stripTarget();

    std::cout << train.data.size() << std::endl;
    std::cout << trainPredictor.data.size() << std::endl;
    std::cout << trainTarget.data.size() << std::endl;

    SimpleLinearRegression slr = SimpleLinearRegression(trainPredictor, trainTarget);

    slr.printCoefficients();

    DataFrame testPredictor = test.stripPredictor();

    DataFrame predictedData = slr.getPredictedData(testPredictor);

    df.sort();
    predictedData.sort();

    Plot::simplePlot(df);
    Plot::simplePlot(predictedData);
}
