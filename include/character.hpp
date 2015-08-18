//====================
// Include Guard
#ifndef __CHARACTER_HPP_INCLUDED__
#define __CHARACTER_HPP_INCLUDED__ 

//====================
// Forward declared dependencies
class Item;

//====================
// Included dependencies
#include <map>
#include <string>

//====================
// Class
class Character 
{
    public:
        // Constructor
        Character();

    private:
        int hp_;
        std::map<std::string, int> attributes_;
        std::map<std::string, Item*> equipped_;
        std::map<std::string, int> inventory_;
};

#endif

