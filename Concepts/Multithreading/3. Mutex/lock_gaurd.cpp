#include<iostream>
#include<thread>
#include<chrono>
#include<mutex> //Mutual Exclusion.

std::mutex m;

void counting_threads(int &count){
    for(int i=0;i<1000;i++){
        std::lock_guard<std::mutex> lg(m); // RAII Technique similar to what you have in smart pointers (Resource Allocation is Initialization).
        int temp = count;
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        count = temp + 1;
        // This automatically unlocks when the scope for lg dies.
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