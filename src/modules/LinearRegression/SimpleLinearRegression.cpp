#include "./../../include/LinearRegression/SimpleLinearRegression.h"
#include "./../../include/DataManip/DataManip.h"
#include <iostream>
#include <string>

SimpleLinearRegression::SimpleLinearRegression(DataFrame xTrain, DataFrame yTrain) {
    int n = xTrain.data.size();
    long double xSum = 0;
    long double ySum = 0;
    long double xSquaredSum = 0;
    long double xySum = 0;

    for(int i = 0; i < n; i++) {
        xSum += std::stold(xTrain.data[i][0]);
        ySum += std::stold(yTrain.data[i][0]);
        xSquaredSum += std::stold(xTrain.data[i][0]) * std::stold(xTrain.data[i][0]);
        xySum += std::stold(xTrain.data[i][0]) * std::stold(yTrain.data[i][0]);
    }

    long double bNumerator = (n * xySum) - (xSum * ySum);
    long double bDenominator = (n * xSquaredSum) - (xSum * xSum);
    long double b = bNumerator / bDenominator;

    long double aNumerator = ySum - (b * xSum);
    long double aDenominator = n;
    long double a = aNumerator / aDenominator;

    coefficients = std::make_pair(a, b);
}

long double SimpleLinearRegression::printCoefficients() {
    std::cout << "y = " << coefficients.first << " + " << coefficients.second << "x" << std::endl;
    return 0;
}

DataFrame SimpleLinearRegression::getPredictedData(DataFrame xTestPredictor) {
    DataFrame predictedData;
    for(int i = 0; i < (int)xTestPredictor.data.size(); i++) {
        std::vector<std::string> row;
        long double y = coefficients.first + coefficients.second * std::stold(xTestPredictor.data[i][0]);
        row.push_back(xTestPredictor.data[i][0]);
        row.push_back(std::to_string(y));
        predictedData.pushBack(row);
    }
    return predictedData;
}

