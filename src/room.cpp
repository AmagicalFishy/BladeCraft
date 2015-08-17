#include "room.hpp"
#include <iostream>

// Unique room serial number
int Room::roomSerialCounter = 000000;

// Default construct empty room
Room::Room() {
    roomID_ = roomSerialCounter++;
};

// Get number of items in room
std::size_t Room::numItems() { return itemsInThisRoom_.size_; };

// Add item to room
void Room::addItem(Item item) { itemsInThisRoom_.addObject(item); };

// Get iterator which iterates over items in room
LinkedList<Item>::ListIterator Room::getItems() { 
    return itemsInThisRoom_.begin(); 
};

// Show description of room
void Room::showDescription() { 
    std::cout << "IT'S A BIG FUCKING ROOM"; 
};

