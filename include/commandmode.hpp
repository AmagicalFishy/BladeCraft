//====================
// Include Guard
#ifndef __COMMANDMODE_HPP_INCLUDED__
#define __COMMANDMODE_HPP_INCLUDED__

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



