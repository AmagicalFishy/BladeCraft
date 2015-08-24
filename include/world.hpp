//====================
// Include Guard
#ifndef WORLD_HPP_INCLUDED
#define WORLD_HPP_INCLUDED

//====================
// Forward declared dependencies

class Soul;

//====================
// Included dependencies
#include <queue>
#include <tuple>
#include "attacks.hpp"
#include "handlers.hpp"
#include "notifiers.hpp"

//====================
// Class
class World {
    public:
        World();
        void regAttack(Soul* attacker, Soul* target, \
                Attacks::Attack* attack);

        CombatNotifier combatNotifier_;
        AttackHandler attackHandler_;

    private:
        friend AttackHandler;
        std::queue< std::tuple<Soul*, Soul*, Attacks::Attack*> > combatEvents_;
};

#endif
  
