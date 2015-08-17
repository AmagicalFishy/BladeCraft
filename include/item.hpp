//====================
// Include Guard
#ifndef __ITEM_HPP_INCLUDED__
#define __ITEM_HPP_INCLUDED__

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
        // Constructors
        Item();
        Item(std::string name, int typeID);
        Item(std::string name);
        Item(std::string name, std::string material);
        Item(std::string name, std::string material, 
                std::array<int, 2> stats);
        // ------
        int getID();
        std::map<std::string, int> getStats();

        float weight_;
        std::string name_;
        std::string material_;

    private:
        int uniqueID_;
        int itemID_;
        std::array<int, 2> enhancements_;

};

#endif

