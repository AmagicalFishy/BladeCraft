//====================
// Include Guard
#ifndef __ROOM_HPP_INCLUDED__
#define __ROOM_HPP_INCLUDED__ 

//====================
// Forward declared dependencies
class Item;

//====================
// Included dependencies
#include "linkedlist.hpp"
#include "item.hpp"

//====================
// Class
class Room {
    public:
        Room();

        static int roomSerialCounter; // Counter of room serial numbers
        int roomID_;

        std::size_t numItems();
        void addItem(Item& item);
        LinkedList<Item>::ListIterator getItems();
        void showDescription();

        LinkedList<Item> itemsInThisRoom_;
    private:
};
        
#endif

