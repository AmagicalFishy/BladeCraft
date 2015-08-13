//====================
// Include Guard
#ifndef __CHARACTER_HPP_INCLUDED__
#define __CHARACTER_HPP_INCLUDED__ 

//====================
// Forward declared dependencies
class Item;

//====================
// Included dependencies
#include <map>
#include <string>

//====================
// Class
class Character 
{
    public:
        // Constructor
        Character();

        // Getter and setter methods
        int getAttribute(std::string name);
        void setAttribute(std::string name, int value);
        int getHP();
        void setMaxHP(int new_max);
        void changeHP(int delta);

        // Add item to inventory
        void getItem(std::string);

        // Equip an item
        void equip(std::string item_name);

        // Return pointer to whatever is equipped 
        Item* getEquipped(std::string slot);

        // Attacks
        int swing();

    private:
        int m_maxhp;
        int m_hp;
        std::map<std::string, int> m_attributes;
        std::map<std::string, Item*> m_equipped;
        std::map<std::string, int> m_inventory;
};

#endif

