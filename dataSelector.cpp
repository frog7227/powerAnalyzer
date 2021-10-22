//
// Created by Andrew on 10/21/2021.
//
#include <cmath>
#include "iostream"
void dataSelector(double* inputData,int inputLen, int* outputLen, int* startLoc){// picks the max from the beginning and end and returns the data
    int maxLocLeft = 0, maxLocRight = 0;
    for (int i = 1; i < inputLen; ++i) {// finds the max of the file
        if (inputData[i] < inputData[i - 1] && inputData[i] > 0) {
            maxLocLeft = i-1;
            break;
        }
    }
        for (int i = inputLen-1; i > 1; --i) {// finds the max of the file
            if(inputData[i] > inputData[i-1] && inputData[i] > 0){
                maxLocRight = i;
                break;
            }
        }
        *outputLen = maxLocRight-maxLocLeft;
        *startLoc = maxLocLeft;
    std::cout << "LeftLoc: " << maxLocLeft << ", RightLoc: " << maxLocRight << ", outputLen: " << *outputLen << std::endl;

}