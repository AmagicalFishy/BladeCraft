//====================
// Include Guard
#ifndef __ROOM_HPP_INCLUDED__
#define __ROOM_HPP_INCLUDED__ 

//====================
// Forward declared dependencies

//====================
// Included dependencies
#include "common/linkedlist.hpp"



//====================
// Class
class Room {
    public:
        static int room_serial; // Counter of room serial numbers
        Room();
        void addItem(Item* item);

    private:
        int roomID_;
        int numberOfItems_;
        ItemList itemsInThisRoom_;
        
#endif

