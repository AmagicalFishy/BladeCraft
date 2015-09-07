//====================
// Include Guard
#ifndef COMMAND_HPP_INCLUDED
#define COMMAND_HPP_INCLUDED

//====================
// Forward declared dependencies
class Soul;

//====================
// Included dependencies
#include <set>
#include <string>
#include <vector>

//====================
// Command Namespace 

namespace Commands {
    template<typename T> T* fetchObject(std::string name, 
            std::set<T*> objectSet);

    std::vector<std::string> split(const std::string command, 
        char delimiter);

    bool parseCommand(Soul* playerSoul, std::string command);  
}
#endif

