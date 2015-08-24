#include <iostream>
#include <tuple>
#include "attacks.hpp"
#include "notifiers.hpp"
#include "soul.hpp"
#include "world.hpp"

//====================
// Handler Base Class
Handler::Handler(World* currentWorld) : currentWorld_(currentWorld) {}
void Handler::recieveNotification() { std::cout << "Notified!"; }
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
}

