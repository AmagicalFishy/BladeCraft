#include "item.hpp"
#include <iostream>

// Unique ID key for every item
int Item::itemSerialCounter = 0;

// Constructors
Item::Item() { 
    uniqueID_ = itemSerialCounter++;
    enhancements_["Str"] = 0;
    enhancements_["Def"] = 0;
};
Item::Item(std::string name) : Item::Item() { name_ = name; };
Item::Item(std::string name, std::array<int, 2> stats)
: Item::Item(name) {
    enhancements_["Str"] = stats[0];
    enhancements_["Def"] = stats[1];
};

// Return unique item ID
int Item::getID() { return uniqueID_; }

// Return map of stats
std::map<std::string, int> Item::getStats() { return enhancements_; };
