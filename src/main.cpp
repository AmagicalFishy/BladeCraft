#include <iostream>
#include <string>
#include <array>
#include "headerlist.hpp"

//scanf for 

int main() {
    bool gameRunning = true;
    std::string command;

    while ( gameRunning == true ) { 
        std::cout << "Command: ";
        getline(std::cin, command);
    }

    return 0;
};
