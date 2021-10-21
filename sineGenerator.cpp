//
// Created by Andrew on 10/21/2021.
//
#include "math.h"

void generateSine(double* x, int size, double amplitude, float fundamental, int sampleRate, float phase){
    const double pi = 3.1415926535897932384626433832795;
    if(sampleRate/2 < (int)ceil(fundamental)){// if nyquist-shannon is not satisfied x is zeroed
        for(int i = 0; i<size; ++i) x[i] = 0;
        return;
    }
    for (int i = 0; i < size; ++i) {
        x[i] = amplitude*sin(2.*pi*fundamental*i/(float)sampleRate + phase*pi/180.);
    }

}