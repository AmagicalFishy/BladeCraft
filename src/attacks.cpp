#include "attacks.hpp"
#include "soul.hpp"

Attacks::Attack::Attack(Soul* attacker, float damageMultiplier) {
    damage_ = damageMultiplier * 
        ( std::get<0>(attacker->getAttribute("str")) + 
          std::get<1>(attacker->getAttribute("str")) );
}

int Attacks::Attack::getDamage() { return damage_; }
