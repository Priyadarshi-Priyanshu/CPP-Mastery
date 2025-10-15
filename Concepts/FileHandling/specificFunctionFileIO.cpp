#include <fstream>
#include <iostream>
// fstreambase is the parent class for all file handling.

int main(){
    // // Connecting my main thread with the file operation to write in a file.
    // std::ofstream hout("names.txt");

    // std::string name;
    // std::cout<<"Enter your name : ";
    // std::cin>> name;

    // // Writing in the file now.
    // hout<<"My name is " + name<<std::endl<<"hui hui hui";

    // hout<<"I will dedicate my 1 year completely to master programming like no one has";

    // hout.close();

    std::ofstream hout;

    hout.open("sample output.txt");
    hout<<"This is me \n";
    hout<<"This is me also";
    hout<<"This is also me";
    hout.close();

    std::ifstream hin;

    std::string content; 
    hin.open("sample input.txt");
    while(hin.eof()==0){
        getline(hin,content);
        std::cout<<content<<std::endl;
    }

    hin.close();
    return 0;
}