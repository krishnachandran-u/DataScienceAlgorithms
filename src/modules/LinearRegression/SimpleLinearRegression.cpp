#include <./../../include/SimpleLinearRegression/SimpleLinearRegression.h>
#include <./../../include/DataManip/DataManip.h>
#include <iostream>
#include <string>

SimpleLinearRegression::SimpleLinearRegression(DataFrame xTrain, DataFrame yTrain) {
    int n = xTrain.size();

    long double xSum = 0;
    long double ySum = 0;
    long double xSquaredSum = 0;
    long double xySum = 0;
    for(int i = 0; i < n; i++) {
        xSum += std::stold(xTrain[i]);
        ySum += std::stold(yTrain[i]);
        xSquaredSum += std::stold(xTrain[i]) * std::stold(xTrain[i]);
        xySum += std::stold(xTrain[i]) * std::stold(yTrain[i]);
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
    for(int i = 0; i < (int)xTest.size(); i++) {
        std::vector<std::string> row;
        for(int j = 0; j < 1; j++) {
            long double y = coefficients.first + coefficients.second * std::stold(xTest[j]);
            row.push_back(std::to_string(x));
            row.push_back(std::to_string(y));
        }
        predictedData.pushBack(row);
    }
}

