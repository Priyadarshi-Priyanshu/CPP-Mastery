#include "mod.h"
#include <fstream> //fstreambase is the parent class for ifstream and ofstream.

int modulo(int a, int b, std::ofstream &hout){
    int result;
    result = a % b;
    hout<<"Modulo : "<<result<<std::endl;
    hout.flush();
    return result;
}
