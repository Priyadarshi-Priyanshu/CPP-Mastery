#include <iostream>
#include <fstream>

/*
 The useful classes for working with files in C++ are :
 1. fstreambase
 2. ifstream  --> derived from fstreambase
 3. ofstream  --> derived from fstreambase

In order to work with files in C++, you will have to open it. Primarily, there are 2 ways to open a file:

1. Using the constructor.
2. Using the member function open() of the class


*/

// This covers the "Using the constructor" method.

int main(){
    
    std::string st = "Writing to the file";
    std::ofstream out("sample output.txt"); // Write Operation.
    std::ifstream in("sample input.txt");
   // in>>st;// this will only give you one token in your code. 

   getline(in,st); // this will give you all the contents in your file.

    std::cout<<"The value in string after read is : "<<st<<std::endl;
    
    return 0;
}