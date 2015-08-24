#include "attacks.hpp"
#include "soul.hpp"

Attacks::Attack::Attack(Soul* attacker, float damageMultiplier) {
    damage_ = damageMultiplier * (attacker->getAttribute("str"));
}

int Attacks::Attack::getDamage() { return damage_; }
