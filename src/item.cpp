#include "item.hpp"

// Unique ID key for every item
int Item::itemSerialCounter = 0;

// Constructors
// Default
Item::Item() { 
    uniqueID_ = itemSerialCounter++;
    enhancements_[0] = 0;
    enhancements_[1] = 0;
};
// With name and item ID
Item::Item(std::string name, int typeID) { 
    name_ = name;
    itemID_ = typeID; 
};
// With name
Item::Item(std::string name) { name_ = name; };
// With name and material
Item::Item(std::string name, std::string material) { 
    name_ = name;
    material_ = material;
};
// With name, material, and stats
Item::Item(std::string name, std::string material, 
std::array<int, 2> stats) {
    name_ = name;
    material_ = material;
    enhancements_[0] = stats[0];
    enhancements_[1] = stats[1];
};

// Return unique item ID
int Item::getID() { return uniqueID_; }

// Return map of stats
std::array<int, 2> Item::getStats() { return enhancements_; };
