#include <iostream>
#include <thread>
#include <fstream>
#include <chrono>

void Layer2(){
    std::cout<<"Hey Priyanshu, Ghost function here \n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::ofstream out("whispers.txt");
    out<<"Ghost calling you from shadows, Arise \n";
    out.close();
}

void Layer1(){
    std::cout<<"Hey Priyanshu, This is Layer1 \n";
    std::thread t2(Layer2);
    std::cout<<"I am going to exit the function and will make the Layer2 a ghost \n";
    t2.detach();
    std::cout<<"Layer1 signing off! \n";
}

int main(){
    std::cout<<"Hello This is main function, I command everything \n";
    std::thread t1(Layer1);
    t1.join();
    std::this_thread::sleep_for(std::chrono::seconds(6));
    return 0;
}