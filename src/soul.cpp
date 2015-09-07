#include "attacks.hpp"
#include "info.hpp"
#include "item.hpp"
#include "soul.hpp"
#include "world.hpp"

int Soul::soulSerialCounter = 0;
Soul::Soul() : HP_(100), ID_(soulSerialCounter), maxHP_(100) { 
    ++soulSerialCounter;

    attributes_["str"] = 5;
    attributes_["def"] = 3;

    itemAttributes_["str"] = 0;
    itemAttributes_["def"] = 0;

    equippedItems_["head"] = nullptr;
    equippedItems_["body"] = nullptr;
    equippedItems_["legs"] = nullptr;
    equippedItems_["lhand"] = nullptr;
    equippedItems_["rhand"] = nullptr;
}

Soul::Soul(World* currentWorld) : Soul() { 
    currentWorld_ = currentWorld;
}

Soul::Soul(World* currentWorld, Room* currentRoom) 
: Soul(currentWorld) { 
    currentRoom_ = currentRoom; 
    currentRoom_->insert(this);
}

// Fill soul with information
void Soul::initialize(std::string type, std::string name, 
        std::string description, std::string display) {
    delete info_; // In case info already exists
    info_ = new InfoModule(type, name, description);
}

// Set world of current Soul
void Soul::setWorld(World* currentWorld) { 
    currentWorld_ = currentWorld;
}

// Set target of current Soul
void Soul::setTarget(Soul* target) { target_ = target; }

// Return particular attribute pair (base and item)
std::pair<int, int> Soul::getAttribute(std::string attribute) { 
    std::pair<int, int> attributePair;
    attributePair = 
        std::make_pair
        (attributes_[attribute], itemAttributes_[attribute]);
    return attributePair; 
}

// Return the information module of this soul
InfoModule* Soul::getInfo() { return info_; }

// Equip an item
void Soul::equip(Equipment* toEquip) {
    equippedItems_[toEquip->equippedSlot_] = toEquip;
    toEquip->isEquipped_ = true;

    std::unordered_map<std::string, int>::iterator itemStats;

    // Update attributes based on equipped items
    itemStats = toEquip->additionalAttributes_.begin();
    while (itemStats != 
            toEquip->additionalAttributes_.end()) {
        itemAttributes_[itemStats->first] += itemStats->second;
        ++itemStats;
    }
}

// Change rooms
void Soul::move(std::string direction) {
    currentWorld_->regMoveEvent(this, direction);
}

// Get an item
void Soul::get(Item* toGet) { 
    currentWorld_->regItemEvent(this, toGet, "get");
}

// Remove an item
void Soul::drop(Item* toRemove) {
    currentWorld_->regItemEvent(this, toRemove, "drop");
}

// Unequip an item (by slot!)
void Soul::unequip(std::string slotToUnequip) {
    std::unordered_map<std::string, int>::iterator itemStats;
    itemStats = equippedItems_[slotToUnequip]->
        additionalAttributes_.begin();
    while (itemStats != equippedItems_[slotToUnequip]->
            additionalAttributes_.end()) {
        itemAttributes_[itemStats->first] -= itemStats->second;
        ++itemStats;
    }
    (equippedItems_[slotToUnequip])->isEquipped_ = false;
    equippedItems_[slotToUnequip] = nullptr;
}

// Kill soul
#include <iostream>
void Soul::die() {
    std::cout << "DED\n";
}

// Perform a weak attack
void Soul::weakAttack() { 
    Attacks::Attack* weakAttck = new Attacks::Attack(this, .75); 
    currentWorld_->regAttackEvent(this, this->target_, weakAttck);
}

