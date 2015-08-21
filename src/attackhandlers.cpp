#include "attackhandlers.hpp"
#include "attacktypes.hpp"
#include "soul.hpp"

void AttackHandlers::doAttack(Soul* attacker, Soul* defender, 
        Attack attackParams) {
    const std::map<std::string, int>* offense;
    offense = attacker->getAttributes();

    const std::map<std::string, int>* defense;
    defense = defender->getAttributes();

    int damage = 4;
        //offense["Str"]*attackParams.damageModifier_ - 
        //defense["Def"];

    defender->deltaHP(damage);
}
