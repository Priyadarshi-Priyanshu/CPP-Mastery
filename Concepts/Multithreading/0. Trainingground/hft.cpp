#include<iostream>
#include<thread>
#include<string>
#include<vector>
#include<mutex>

std::mutex m;

void myprinter(std::string text,int char_count,int &ptr,std::string T){
    std::lock_guard<std::mutex> lg(m);
    std::cout<<"Thread"<<T<<": ";
    for(int i=0;i<char_count;i++){
        int pos = ptr % text.size();
        std::cout << text[pos];
        ptr++; // increment by 1 each time
    }
    std::cout<<"\n";
}


int main(){
    std::string text;
    int char_count;
    int thread_count;

    std::cout<<"Please enter the texts you want your iterations on : ";
    std::getline(std::cin,text);

    std::cout<<"Please enter the count of characters you want your iterations on : ";
    std::cin>>char_count;

    std::cout<<"Please enter the count of threads your operations to run on : ";
    std::cin>>thread_count;

    int ptr=0;

    std::vector<std::thread> thread_vector(thread_count);

    int i=0;
    while(true){
        int pos = i % thread_vector.size();
        thread_vector[pos] = std::thread(myprinter,text,char_count,std::ref(ptr),std::to_string(pos+1));
        thread_vector[pos].join();
        i++;
    }

    return 0;
}