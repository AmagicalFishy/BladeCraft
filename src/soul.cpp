#include "soul.hpp"

// Constructor
Soul::Soul(World& world) 
: target_(nullptr), maxHP_(100), theWorld_(world) {
    attributes_["HP"] = maxHP_;
    attributes_["Str"] = 3;
    attributes_["Def"] = 3;
}

void Soul::deltaHP(signed int change) { 
    attributes_["HP"] += change;
}

void Soul::basicAttack() { 
    theWorld_::processAttack(this, target_, 
            AttackType::meleeAttack("weak"));
}

