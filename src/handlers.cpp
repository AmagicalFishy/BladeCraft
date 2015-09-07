#include<iomanip>
#include <iostream>
#include <tuple>
#include <algorithm>
#include "attacks.hpp"
#include "notifiers.hpp"
#include "soul.hpp"
#include "world.hpp"

//====================
// Handler Base Class
Handler::Handler(World* currentWorld) : currentWorld_(currentWorld) {}
void Handler::watchNotifier(Notifier* toWatch) { 
    watching_ = toWatch; 
    watching_->regHandler(this);
}

void Handler::unwatchNotifier(Notifier* toUnwatch) { 
    watching_->unregHandler(this);
    watching_ = nullptr;
}

//====================
// Attack Handler
AttackHandler::AttackHandler(World* currentWorld) 
: Handler(currentWorld) {}

void AttackHandler::recieveNotification() {
    Soul* defender = std::get<1>(currentWorld_->combatEvents_.front());
    Attacks::Attack* attack 
        = std::get<2>(currentWorld_->combatEvents_.front());
    int damage = attack->getDamage();
    
    defender->HP_ -= damage;
    delete attack;
    attack = nullptr;
    currentWorld_->combatEvents_.pop();
    std::cout << defender->getInfo()->getName() << " " << 
        defender->HP_ << "\n";

    if (defender->HP_ <= 0) {
        defender->die();
    }
}

//====================
// Movement Handler
MovementHandler::MovementHandler(World* currentWorld)
: Handler(currentWorld) {}

void MovementHandler::recieveNotification() {
    Soul* soul = std::get<0>(currentWorld_->movementEvents_.front());
    std::string direction = 
        std::get<1>(currentWorld_->movementEvents_.front());
    Room* destinationRoom = 
        soul->currentRoom_->getRoom(direction);

    // Do nothing if there isn't an exit there
    if (destinationRoom == false) { 
        std::cout << "\nThere is no exit in that direction.\n\n";
        currentWorld_->movementEvents_.pop();
        return; 
    }
    
    // Move soul into specified room
    soul->currentRoom_->remove(soul); 
    soul->currentRoom_ = destinationRoom;
    destinationRoom->insert(soul);
    currentWorld_->movementEvents_.pop();

    // Print out room description
    std::cout << BOLDWHITE << "\n" << 
        destinationRoom->getInfo()->getName() << "\n" << RESET;
    std::cout << GREEN << 
        destinationRoom->getInfo()->getDescription() << "\n\n" << 
        RESET;

    // Print out items and Souls
    int maxSize = std::max(destinationRoom->itemsInRoom_.size(), 
            destinationRoom->soulsInRoom_.size() - 1);
    formatPrint("Items:");
    formatPrint("Souls:");
    std::cout << "\n";
    auto items = destinationRoom->itemsInRoom_.begin();
    auto souls = destinationRoom->soulsInRoom_.begin();
    ++souls; // Skip the player
    for (int ii = 0; ii < maxSize; ++ii) {
        if (items != destinationRoom->itemsInRoom_.end()) {
            formatPrint("- " + (*items)->getInfo()->getName());
            ++items;
        }
        else { formatPrint(" "); }

        if (souls != destinationRoom->soulsInRoom_.end()) {
            formatPrint("- " + (*souls)->getInfo()->getName());
            ++souls;
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

//====================
// Item Handler
ItemHandler::ItemHandler(World* currentWorld)
: Handler(currentWorld) {}

void ItemHandler::recieveNotification() {
    enum ItemAction { drop = 0, get, equip};

    Soul* soul = std::get<0>(currentWorld_->itemEvents_.front());
    Item* item = std::get<1>(currentWorld_->itemEvents_.front());
    std::string command = 
        std::get<2>(currentWorld_->itemEvents_.front());

    std::map<std::string, int> itemAction;
    itemAction["drop"] = drop;
    itemAction["get"] = get;
    //itemAction["equip"] = equip;

    switch (itemAction[command]) {
        case drop:
            soul->inventory_.erase(item);
            soul->currentRoom_->insert(item);

        case get:
            soul->currentRoom_->remove(item);
            soul->inventory_.insert(item);
    }

    currentWorld_->itemEvents_.pop();
}

// Function that helps format how items and souls in room print
const char separator = ' ';
const int columnWidth = 30;

void formatPrint(std::string toPrint) {
    std::cout << std::left << std::setw(columnWidth) << 
        std::setfill(separator) << toPrint;
}

