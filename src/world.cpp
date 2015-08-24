#include "world.hpp"

World::World() : attackHandler_(AttackHandler(this)) {
    attackHandler_.watchNotifier(&combatNotifier_);
}

void World::regAttack(Soul* attacker, Soul* target, 
        Attacks::Attack* attack) {
    std::tuple<Soul*, Soul*, Attacks::Attack*> 
        combatEvent(attacker, target, attack); 
    combatEvents_.push(combatEvent);
    combatNotifier_.notify();
}
