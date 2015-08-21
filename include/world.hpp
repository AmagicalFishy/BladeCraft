#include "world.hpp"

World::World() : attackTypeLink_(new AttackType;) {}
World::~World() { 
    delete attackTypeLink;
}

World::processAttack(Soul* attacker, Soul* target, 
        AttackType attackType) {
    attackHandler = AttackHandlers->get(attacker, target, attackType);
    if (attackHandler) { 
        attackHandler.doAttack();
    }
}
