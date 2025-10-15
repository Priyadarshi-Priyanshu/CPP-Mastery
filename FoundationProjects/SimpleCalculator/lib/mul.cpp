#include "mul.h"
#include <fstream>

int multiplication(int a, int b, std::ofstream &hout){
    int result;
    result = a * b;
    hout<<"Multiplication : "<<result<<std::endl;
    hout.flush();
    return result;
}
