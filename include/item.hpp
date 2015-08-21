//====================
// Include Guard
#ifndef ITEM_HPP_INCLUDED
#define ITEM_HPP_INCLUDED

//====================
// Forward declared dependencies
// class material;

//====================
// Included dependencies
#include <string>
#include <array>
#include <map>

//====================
// Classes

class Item {
    public: 
        static int itemSerialCounter;
        Item();
        Item(std::string name);
        Item(std::string name, std::array<int, 2> stats);

        int getID();
        std::map<std::string, int> getStats();

        std::string name_;

    private:
        int uniqueID_;
        int itemID_;
        std::map<std::string, int> enhancements_;

};

#endif

