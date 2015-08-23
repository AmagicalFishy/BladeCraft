//====================
// Include Guard
#ifndef ATTACKHANDLERS_HPP_INCLUDED
#define ATTACKHANDLERS_HPP_INCLUDED

//====================
// Forward declared dependencies
//
class Soul;
class Attack;

//====================
// Included dependencies
#include <map>
#include <string>

//====================
// Class
namespace AttackHandlers {
        void doAttack(Soul* attacker, Soul* defender, 
                Attack attackParam);
};

#endif

