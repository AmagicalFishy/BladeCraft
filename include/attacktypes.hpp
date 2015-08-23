//====================
// Include Guard
#ifndef ATTACKTYPES_HPP_INCLUDED
#define ATTACKTYPES_HPP_INCLUDED

//====================
// Forward declared dependencies
//
class AttackHandler;

//====================
// Included dependencies
#include <string>
#include <map>

//====================
// Class
struct Attack {
    Attack(float damageModifier, std::string elementModifier,
        int staminaDrain);
    float damageModifier_;
    std::string elementModifier_;
    int staminaDrain_;
};

namespace AttackType {
        Attack meleeAttack(std::string strength);
};

#endif

