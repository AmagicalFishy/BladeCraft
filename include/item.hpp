//====================
// Include Guard
#ifndef ITEM_HPP_INCLUDED
#define ITEM_HPP_INCLUDED

//====================
// Forward declared dependencies
class Room;
class InfoModule;

//====================
// Included dependencies
#include <string>
#include <unordered_map>

//====================
// Item Superclass
class Item {
    public: 
        static int itemSerialCounter;
        Item(Room* currentRoom);
        ~Item();
        void initialize(std::string type, std::string name,
                std::string description);
        InfoModule* getInfo(); 

    private:
        Item();
        InfoModule* info_;
        int ID_;
};

// Equipment subclass
class Equipment : public Item {
    public:
        Equipment(std::string equippedSlot, Room* currentRoom);
        void setAttribute(std::string attribute, int amount);
        bool isEquipped_;

        std::string equippedSlot_;
        std::unordered_map<std::string, int> additionalAttributes_;

    private:
};


#endif

