#include "info.hpp"
#include "room.hpp"
#include <iostream>

// Unique room serial number
int Room::roomSerialCounter = 000000;

// Default construct empty room
Room::Room(std::array<int, 3> ID) : info_(nullptr), ID_(ID) { 
    ID_ = ID; 
    linkedRooms_["north"] = nullptr;
    linkedRooms_["east"] = nullptr;
    linkedRooms_["south"] = nullptr;
    linkedRooms_["west"] = nullptr;
    linkedRooms_["up"] = nullptr;
    linkedRooms_["down"] = nullptr;
};

Room::~Room() { delete info_; }

// Initialize room w/ actual info provided
void Room::initialize(std::string type, std::string name,
        std::string description) { 
    if (info_ != nullptr) { delete info_; }
    info_ = new InfoModule(type, name, description);
}

// Return room's info module
InfoModule* Room::getInfo() { return info_; }

// Insert soul or item into room
void Room::insert(Soul* soul) { soulsInRoom_.insert(soul); }
void Room::insert(Item* item) { itemsInRoom_.insert(item); }

// Remove soul or item from room
void Room::remove(Soul* soul) { soulsInRoom_.erase(soul); }
void Room::remove(Item* item) { itemsInRoom_.erase(item); }

// Link two rooms together
void Room::link(Room* toLink, std::string direction) { 
    linkedRooms_[direction] = toLink;
}

// Return room in specified direction
Room* Room::getRoom() { return this; }
Room* Room::getRoom(std::string direction) {
    return linkedRooms_[direction];
}
std::array<int, 3> Room::getID() { return ID_; }


