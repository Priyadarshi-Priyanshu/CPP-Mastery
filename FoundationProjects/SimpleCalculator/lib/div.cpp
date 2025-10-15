#include "div.h"
#include <fstream> //fstreambase is the parent class for ifstream and ofstream.

int division(int a, int b, std::ofstream &hout){
    int result;
    result = a / b;
    hout<<"Division : "<<result<<std::endl;
    hout.flush();

    return result;
}