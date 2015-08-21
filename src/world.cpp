#include "world.hpp"
#include "attacktypes.hpp"
#include "attackhandlers.hpp"

void World::processAttack(Soul* attacker, Soul* target, Attack attack) {
    AttackHandlers::doAttack(attacker, target, attack);
}
