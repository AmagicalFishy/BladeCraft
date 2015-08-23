#include "attacktypes.hpp"

Attack::Attack(float damageModifier, std::string elementModifier,
               int staminaDrain) 
: damageModifier_(damageModifier), elementModifier_(elementModifier),
    staminaDrain_(staminaDrain) {}

Attack AttackType::meleeAttack(std::string strength) {
    float damageModifier;
    int staminaDrain;
    enum {
        weak = 1,
        normal,
        strong
    };

    std::map<std::string, int> strengthMap;
    strengthMap["weak"] = weak;
    strengthMap["normal"] = normal;
    strengthMap["strong"] = strong;

    switch(strengthMap[strength]) {
        case weak:
            damageModifier = .75;
            staminaDrain = 5;
        case normal:
            damageModifier = 1.0;
            staminaDrain = 10;
        case strong:
            damageModifier = 1.25;
            staminaDrain = 15;
    }
    return Attack(damageModifier, "None", staminaDrain);
}
