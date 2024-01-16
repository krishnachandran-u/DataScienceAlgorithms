#include <./../../include/LinearRegression/SimpleLinearRegression.h>
#include <./../../include/DataManip/DataManip.h>
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
        ySum += std::stold(yTrain.data[i][1]);
        xSquaredSum += std::stold(xTrain.data[i][0]) * std::stold(xTrain.data[i][0]);
        xySum += std::stold(xTrain.data[i][0]) * std::stold(yTrain.data[i][1]);
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

DataFrame SimpleLinearRegression::predict(DataFrame xTest) {
    DataFrame predictedData;
    std::vector<std::string> row;
    for(int i = 0; i < (int)xTest.data.size(); i++) {
        long double y = coefficients.first + coefficients.second * std::stold(xTest.data[i][0]);
        row.push_back(std::to_string(xTest.data[i][0]));
        row.push_back(std::to_string(y));
        predictedData.pushBack(row);
    }
}

