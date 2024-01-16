#ifndef LINEARREGRESSION_H
#define LINEARREGRESSION_H

#include "./../DataManip/DataManip.h"
#include <iostream>

class SimpleLinearRegression {
    private:
        std::pair<long double, long double> coefficients;
    public:
        SimpleLinearRegression(DataFrame xTrain, DataFrame yTrain);
        long double printCoefficients();
        DataFrame predict(DataFrame xTest);
        
}

#endif
