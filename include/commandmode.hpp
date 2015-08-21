//====================
// Include Guard
#ifndef COMMANDMODE_HPP_INCLUDED
#define COMMANDMODE_HPP_INCLUDED

//====================
// Forward declared dependencies

//====================
// Included dependencies
#include <string>

//====================
// Class

class CommandMode{
    public:
        CommandMode();
        void parseCommand(std::string command);
};

#endif



