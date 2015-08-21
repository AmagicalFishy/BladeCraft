#include "soul.hpp"
#include "world.hpp"
#include "attacktypes.hpp"

// Constructor
Soul::Soul(World* world) 
: target_(nullptr), maxHP_(100), theWorld_(world) {
    attributes_["HP"] = maxHP_;
    attributes_["Str"] = 3;
    attributes_["Def"] = 3;
}

void Soul::target(Soul* newTarget) { target_ = newTarget; }

const std::map<std::string, int>* Soul::getAttributes() { 
    return &(attributes_); 
}

void Soul::deltaHP(signed int change) { 
    attributes_["HP"] += change;
}

void Soul::weakAttack() { 
    theWorld_->processAttack(this, target_, 
            AttackType::meleeAttack("weak"));
}

