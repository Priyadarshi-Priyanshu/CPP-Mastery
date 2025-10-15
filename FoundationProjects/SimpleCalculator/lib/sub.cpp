#include "sub.h"
#include <fstream>

int substraction(int a, int b, std::ofstream &hout){
    int result;
    result = a - b;
    hout<<"Substraction : "<<result<<std::endl;
    hout.flush();
    return result;
}