//====================
// Include Guard
#ifndef SOUL_HPP_INCLUDED
#define SOUL_HPP_INCLUDED

//====================
// Forward declared dependencies
class Equipment;
class InfoModule;
class Item;
class MovementHandler;
class ItemHandler;
class Room;
class World;

//====================
// Included dependencies
#include "command.hpp"
#include <unordered_map>
#include <set>

//====================
// Class
class Soul {
    public:
        static int soulSerialCounter;
        Soul(World* currentWorld); 
        Soul(World* currentWorld, Room* currentRoom); 
        void initialize(std::string type, std::string name, 
                std::string description, std::string display);
        void setWorld(World* currentWorld); 
        void setTarget(Soul* target);

        std::pair<int, int> getAttribute(std::string attribute);
        void setAttribute(std::string attribute, int amount);
        InfoModule* getInfo();

        void move(std::string direction);
        void get(Item* toGet);
        void drop(Item* toGet);
        void equip(Equipment* toEquip);
        void unequip(std::string slotToUnequip);
        void die();

        void weakAttack();

        int HP_;
        Room* currentRoom_;

    private:
        Soul();
        int ID_; 
        friend World;
        friend MovementHandler;
        friend ItemHandler;
        friend bool Commands::parseCommand( Soul* playerSoul, 
                std::string command);
        InfoModule* info_;
        int maxHP_; 
        World* currentWorld_;
        Soul* target_;
        std::unordered_map<std::string, int> attributes_;
        std::set<Item*> inventory_;

    protected:
        friend Equipment;
                std::unordered_map<std::string, int> itemAttributes_;
        std::unordered_map<std::string, Equipment*> equippedItems_;

};

#endif

