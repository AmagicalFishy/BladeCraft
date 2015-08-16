#include "room.hpp"
#include <iostream>

int Room::roomSerialCounter = 000000;

Room::Room() {
    roomID_ = roomSerialCounter;
    roomSerialCounter++;
};

std::size_t Room::numItems() { return itemsInThisRoom_.size_; };
void Room::addItem(Item item) { itemsInThisRoom_.addObject(item); };
LinkedList<Item>::ListIterator Room::getItems() { 
    return itemsInThisRoom_.getIterator(); 
};
void Room::showDescription() { 
    std::cout << "IT'S A BIG FUCKING ROOM"; 
};

