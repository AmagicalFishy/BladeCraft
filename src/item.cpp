#include "item.hpp"
#include "room.hpp"
#include "info.hpp"
#include <iostream>

// Unique ID key for every item
int Item::itemSerialCounter = 0;

Item::Item(Room* currentRoom) { 
    ID_ = itemSerialCounter;
    ++itemSerialCounter;
    currentRoom->insert(this);
}

Item::~Item() { delete info_; }

void Item::initialize(std::string type, std::string name,
                std::string description) { 
    info_ = new InfoModule(ID_, type, name, description);
}

InfoModule* Item::getInfo() { return info_; }

// Equipment
Equipment::Equipment(std::string equippedSlot, Room* currentRoom)
: Item(currentRoom) { 
    isEquipped_ = false;
    equippedSlot_ = equippedSlot;
    additionalAttributes_["str"] = 0;
    additionalAttributes_["def"] = 0;
}

void Equipment::setAttribute(std::string attribute, int amount) {
    additionalAttributes_[attribute] = amount;
}


