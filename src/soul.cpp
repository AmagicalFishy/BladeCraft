#include "attacks.hpp"
#include "soul.hpp"
#include "world.hpp"

Soul::Soul() : HP_(100), maxHP_(100) { 
    attributes_["str"] = 5;
    attributes_["def"] = 3;
}

Soul::Soul(World* currentWorld) : Soul() { 
    currentWorld_ = currentWorld;
}

void Soul::setWorld(World* currentWorld) { 
    currentWorld_ = currentWorld;
}

void Soul::setTarget(Soul* target) { target_ = target; }

int Soul::getAttribute(std::string attribute) { 
    return attributes_[attribute]; 
}

void Soul::weakAttack() { 
    Attacks::Attack* weakAttck = new Attacks::Attack(this, .75); 
    currentWorld_->regAttack(this, this->target_, weakAttck);
}
