#include "room.hpp"

ItemList::next() { current_ = current_::next; }
ItemNode::ItemNode(Item* item) { item_ = item; }

Room::room_serial = 000000;
Room::Room() {
    // Sets ID number and increments ID
    roomID = room_serial;
    room_serial += 1;
    numberOfItems_ = 0;
}
Room::addItem(Item* item) {
    tmpItem = ItemNode(item);
    if (numberOfItems == 0) { 
        itemsInThisRoom_::next = tmpItem;
        itemsInThisRoom_ = tmpItem;
    }

    else {
        itemsInThisRoom_::next = ItemNode(item);
