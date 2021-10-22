#include <iostream>
#include <fstream>
#include <cmath>
const double sqrt2 = 1.41421356237309504880167887242097; // save computation

void generateSine(double* x, int size, double amplitude, float fundamental, int sampleRate, float phase); // in other file
double averagePower(const double* inputVoltage, const double* inputCurrent, int dataLen);
void dataSelector(double* inputData,int inputLen, int* outputLen, int* startLoc);
int main() {

    double outputData[167], voltage[167], current[167],current1[167];

    generateSine(&voltage[0],167, 120 * sqrt2, 60,1000,0);
    generateSine(&current[0],167, 1 * sqrt2, 60,1000,0);
    double power = averagePower(&voltage[0],&current[0],167);
    std::cout << "The average power over the interval was: " << power << std::endl;


    std::ofstream file;
    file.open("output.csv");// write the output CSV for testing
    file << "index,Voltage,Current" << std::endl;
    for (int i = 0; i < 167; ++i) {
        file << i << "," << voltage[i] << "," << current[i] << std::endl;
    }
    file.close();


    return 0;
}

double averagePower(const double *inputVoltage, const double *inputCurrent, int dataLen) {// sample rate must be 4x the maximum frequency
    double prevValue = 0;
    double energy = 0;
    for (int i = 0; i < dataLen; ++i) {//trap approximation of the total real energy consumed, some simplification is done beforehand, aka. the 1/T in the integration cancels with the calculation in the return line
        energy += (inputVoltage[i]*inputCurrent[i]+prevValue)/2;
        prevValue=inputVoltage[i]*inputCurrent[i];
    }
    return energy/(double)dataLen;
}