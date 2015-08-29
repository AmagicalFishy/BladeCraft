//====================
// Include Guard
#ifndef SOUL_HPP_INCLUDED
#define SOUL_HPP_INCLUDED

//====================
// Forward declared dependencies
class Equipment;
class Item;
class MovementHandler;
class ItemHandler;
class Room;
class World;

//====================
// Included dependencies
#include <unordered_map>
#include <set>

//====================
// Class
class Soul {
    public:
        Soul(World* currentWorld); 
        Soul(World* currentWorld, Room* currentRoom); 
        void setWorld(World* currentWorld); 
        void setTarget(Soul* target);

        std::pair<int, int> getAttribute(std::string attribute);
        void setAttribute(std::string attribute, int amount);

        void move(std::string direction);
        void get(Item* toGet);
        void drop(Item* toGet);
        void equip(Equipment* toEquip);
        void unequip(std::string slotToUnequip);
        void die();

        void weakAttack();
        int HP_;

    private:
        Soul();
        friend World;
        friend MovementHandler;
        friend ItemHandler;
        int maxHP_; 
        World* currentWorld_;
        Room* currentRoom_;
        Soul* target_;
        std::unordered_map<std::string, int> attributes_;
        std::set<Item*> inventory_;

    protected:
        friend Equipment;
                std::unordered_map<std::string, int> itemAttributes_;
        std::unordered_map<std::string, Equipment*> equippedItems_;

};

#endif

