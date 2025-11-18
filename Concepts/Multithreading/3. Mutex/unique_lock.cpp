#include<iostream>
#include<thread>
#include<chrono>
#include<mutex> //Mutual Exclusion.

std::mutex m;

/*
Topic : unique_lock in C++ (std::unique_lock<mutex> lock(m1))

NOTES:
1. The class unique_lock is a mutex ownership wrapper.
2. It allows:
    a. Can have different locking strategies.
    b. time-constrained attempts at locking (try_lock_for, try_lock_until)
    c. recursive locking
    d. transfer of lock ownership (move not copy)
    e. condition variables. 

Locking Strategies

Type                         Effects(s)
1. defer_lock                do not acquire ownership of the mutex.
2. try_to_lock               try to acquire ownership of the mutex without blocking.
3. adopt_lock                assume the calling thead already has ownership of the mutex.
*/

// Example: 1 (Normal locking)
void counting_threads_normal_lock(int &count){
    for(int i=0;i<1000;i++){
        std::unique_lock<std::mutex> ul(m);
        int temp = count;
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        count = temp + 1;
    }
}

// Example: 2 (deffered_locking)
void counting_threads_defered_lock(int &count){
    for(int i=0;i<1000;i++){
        std::unique_lock<std::mutex> ul(m,std::defer_lock);
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