#include<iostream>
#include<thread>
#include<vector>
#include<mutex>

std::mutex m;

void sum_vector(std::vector<int> &vec,int &sum,std::string t){
    std::cout<<"Thread number : "<<t<<std::endl;
    for(auto v : vec ){
        sum += v;
        std::cout<<"Current Sum Compute :"<<sum<<std::endl;
    }
}

void compare(int &first,int &second, std::string t){
    std::cout<<"Thread number : "<<t<<std::endl;
    if(first>=second)
        std::cout<<"Buy"<<std::endl;
    else
        std::cout<<"Sell"<<std::endl;
}

int main(){
    std::vector<int> v1 = {1,2,3,4,5};
    std::vector<int> v2 = {6,7,8,9,10};

    int sum1 = 0;
    int sum2 = 0;

    std::thread m1(sum_vector,std::ref(v1),std::ref(sum1), "1");
    std::thread m2(sum_vector,std::ref(v2),std::ref(sum2), "2");

    m1.join();
    m2.join();

    std::thread m3(compare,std::ref(sum1),std::ref(sum2),"3");

    m3.join();
    
    return 0;
}
