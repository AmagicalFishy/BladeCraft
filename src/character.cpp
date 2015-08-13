#include "character.hpp"

// Constructor
Character::Character() {};

// Getter and setter methods
int Character::getAttribute(std::string name) {
    return m_attributes.find(name)->second; 
};
void Character::setAttribute(std::string name, int value) {
    m_attributes.at(name) = value;
}
int Character::getHP() { return m_hp; };
void Character::setMaxHP(int new_max) { m_maxhp = new_max; };
void Character::changeHP(int delta) { m_hp += delta; };

// Equip and item
//void Character::equip(std::string item_name) {
//    m_inventory.at}

// Return pointer to whatever is equipped
Item* Character::getEquipped(std::string slot) {
    return m_equipped.find(slot)->second;
}

// Attacks 
int Character::swing() {
    int damage = m_attributes.find("Str")->second;
    return damage;
};



