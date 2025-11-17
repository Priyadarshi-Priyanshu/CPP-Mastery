#include<iostream>
#include<thread>
#include<chrono>

void counting_threads(int &count){
    for(int i=0;i<1000;i++){
        int temp = count;
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        count = temp + 1;
    }
}

int main(){
    std::thread t[10];
    int count = 0;
    std::cout<<"The value of count : "<<count<<std::endl;
    for(int i=0;i<10;i++){
        t[i] = std::thread(counting_threads,std::ref(count));
    }

    //joining all the threads
    for(int i=0;i<10;i++)
    t[i].join();

    std::cout<<"The value of count : "<<count<<std::endl;

    return 0;
}