#include "./../../include/Plot/Plot.h"
#include "./../../include/DataManip/DataManip.h"
#include <iostream>
#include <fstream>
#include <cstdio>

void Plot::simplPlot(DataFrame df) {
    std::vector<long double> predictor, target;

    for(int i = 0; i < (int)df.data.size(); i++) {
        predictor.push_back(std::stold(df.data[i][0]));
        target.push_back(std::stold(df.data[i][1]));
    }

    FILE *gnuplotPipe = popen("gnuplot -persist", "w");

    if(gnuplotPipe) {
        fprintf(gnuplotPipe, "plot '-' with lines\n");
        for(int i = 0; i < (int)predictor.size(); i++) {
            fprintf(gnuplotPipe, "%Lf %Lf\n", predictor[i], target[i]);
        }
        fprintf(gnuplotPipe, "e\n");
        pclose(gnuplotPipe);
    }
    else {
        std::cerr << "Error opening pipe to GNUPlot" << std::endl;
    }

    return 0;
}



