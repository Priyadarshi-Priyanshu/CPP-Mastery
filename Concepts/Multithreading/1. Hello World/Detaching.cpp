#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>

void backgroundTask(){
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::ofstream out("background.text");
    out<<"Hi Priyanshu, I have vanished into shadows";
    std::cout << "Background task completed! \n";
    out.close();
}

int main(){

    std::thread t(backgroundTask);

    t.detach(); // run freely in the background

    std::cout<<"Main exits immediately. \n";
    return 0;
}