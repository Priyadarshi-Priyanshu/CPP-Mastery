#include<iostream>
#include<thread>

void worker(){
    std::cout<<"Hello from worker thread! \n";
}

int main () {
    std::cout<<"Hello from main thread! \n";

    // Create a new thread that runs the worker() function.
    std:: thread t(worker);

    // Wait for the thread to finish.
    t.join();

    std::cout << "Woker thread finished! \n";

    return 0;
}