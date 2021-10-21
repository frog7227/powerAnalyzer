#include <iostream>
#include <fstream>
#include "math.h"
const double sqrt2 = 1.4142135623730950488016887242097; // save computation

void generateSine(double* x, int size, double amplitude, float fundamental, int sampleRate, float phase); // in other file
double averagePower(const double* inputVoltage, const double* inputCurrent, int dataLen);
int main() {

    double outputData[100], voltage[101], current[101],current1[101];

    generateSine(&voltage[0],101, 120 * sqrt2, 60,1000,135);
    generateSine(&current[0],101, 1 * sqrt2, 60,1000,135);
    double power = averagePower(&voltage[0],&current[0],101);
    std::cout << "The average power over the interval was: " << power << std::endl;


    std::ofstream file;
    file.open("output.csv");
    file << "index,Voltage,Current" << std::endl;
    for (int i = 0; i < 101; ++i) {
        file << i << "," << voltage[i] << "," << current[i] << std::endl;
    }
    file.close();


    return 0;
}

double averagePower(const double *inputVoltage, const double *inputCurrent, int dataLen) {// sample rate must be 4x the maximum frequency
    double prevValue = 0;
    double energy = 0;
    for (int i = 0; i < dataLen; ++i) {
        energy += (inputVoltage[i]*inputCurrent[i]+prevValue)/2;
        prevValue=inputVoltage[i]*inputCurrent[i];
    }
    return energy/(double)dataLen;
}