#include "world.hpp"

World::World() : attackHandler_(AttackHandler(this)),
movementHandler_(MovementHandler(this)),
itemHandler_(ItemHandler(this)) {
    attackHandler_.watchNotifier(&combatNotifier_);
    movementHandler_.watchNotifier(&movementNotifier_);
    itemHandler_.watchNotifier(&itemNotifier_);
}

void World::regAttackEvent(Soul* attacker, Soul* target, 
        Attacks::Attack* attack) {
    std::tuple<Soul*, Soul*, Attacks::Attack*> 
        combatEvent(attacker, target, attack); 
    combatEvents_.push(combatEvent);
    combatNotifier_.notify();
}

void World::regMoveEvent(Soul* soul, std::string direction) {
    movementEvents_.push(std::make_pair(soul, direction));
    movementNotifier_.notify();
}

void World::regItemEvent(Soul* soul, Item* item, std::string command) {
    std::tuple<Soul*, Item*, std::string> 
        itemEvent(soul, item, command);
    itemEvents_.push(itemEvent);
    itemNotifier_.notify();
}


