#include "add.h"
#include <fstream> //fstreambase is the parent class for ifstream and ofstream.

int addition(int a, int b, std::ofstream &hout){

    int result;
    result = a + b;
    hout<<"Addition : "<<result<<std::endl;
    hout.flush();
    
    return result;
}