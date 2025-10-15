#include "add.h"
#include "sub.h"
#include "mul.h"
#include "div.h"
#include "mod.h"

#include <fstream>
#include <iostream>
#include <cstdlib>   // For getenv
#include <string>

// -------------------- Function to list available operations --------------------
void calculatorFunctionsList(){
    std::cout<<"Lists of functionality available and their corresponding keys"<<std::endl;
    std::cout<<"------------------------------------------------------------------"<<std::endl;
    std::cout<<"1. Add"<<std::endl;
    std::cout<<"2. Sub"<<std::endl;
    std::cout<<"3. Mul"<<std::endl;
    std::cout<<"4. Div"<<std::endl;
    std::cout<<"5. Mod"<<std::endl;
    std::cout<<"6. History"<<std::endl;
    std::cout<<"Press -1 to terminate"<<std::endl;
    std::cout<<"------------------------------------------------------------------"<<std::endl;
}

// -------------------- Function to fetch history --------------------
void fetchingHistory(const std::string &historyFile){
    std::ifstream hin(historyFile);
    std::cout<<"------------------- History --------------------"<<std::endl;

    if(!hin){
        std::cout<<"There is no history yet."<<std::endl;
        return;
    }

    std::string line;
    while (getline(hin, line)) {
        std::cout << line << std::endl;
    }

    std::cout<<"--------------- End of History ----------------"<<std::endl;
    hin.close();
}

// -------------------- Main Function --------------------
int main(){

    // Get environment variable
    const char* envPath = std::getenv("SIMPLECALCULATOR");

    // If env variable is not set, use default path
    std::string dataPath;
    if(envPath){
        dataPath = std::string(envPath) + "/";
    } else {
        std::cerr << "Warning: SIMPLECALCULATOR environment variable not set. Using default path.\n";
        dataPath = "/home/priyanshu/Learning/CPP/FoundationProjects/SimpleCalculator/";
    }

    std::string historyFile = dataPath + "content/history.txt";

    std::cout<<"Calculator App"<<std::endl;
    std::cout<<"History File: " << historyFile << std::endl;

    // Open file for appending
    std::ofstream hout(historyFile, std::ios::app);
    if(!hout){
        std::cerr << "Error: Cannot open history file for writing." << std::endl;
        return 1;
    }

    bool driver = true;

    while(driver){
        int key;
        calculatorFunctionsList();
        std::cout<<"Enter the key based on functionality table above: ";
        std::cin >> key;

        // Option for history or exit
        if(key == 6){
            fetchingHistory(historyFile);
            continue;
        }
        if(key == -1){
            driver = false;
            break;
        }

        // For arithmetic operations
        int a, b;
        std::cout<<"Enter first number: ";
        std::cin >> a;
        std::cout<<"Enter second number: ";
        std::cin >> b;

        switch(key){
            case 1:
                std::cout<<"Value after addition: "<<addition(a,b,hout)<<std::endl;
                break;
            case 2:
                std::cout<<"Value after subtraction: "<<substraction(a,b,hout)<<std::endl;
                break;
            case 3:
                std::cout<<"Value after multiplication: "<<multiplication(a,b,hout)<<std::endl;
                break;
            case 4:
                std::cout<<"Value after division: "<<division(a,b,hout)<<std::endl;
                break;
            case 5:
                std::cout<<"Value after modulo: "<<modulo(a,b,hout)<<std::endl;
                break;

            default:
                std::cout<<"Invalid key entered!"<<std::endl;
                break;
        }
    }

    hout.close();
    return 0;
}
