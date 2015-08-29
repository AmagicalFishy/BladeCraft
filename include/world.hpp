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
#include "headers.hpp"

//====================
// Class
class World {
    public:
        World();
        void regAttackEvent(Soul* attacker, Soul* target, \
                Attacks::Attack* attack);
        void regMoveEvent(Soul* soul, std::string direction);
        void regItemEvent(Soul* soul, Item* item, std::string command);

        CombatNotifier combatNotifier_;
        AttackHandler attackHandler_;

        MovementHandler movementHandler_;
        MovementNotifier movementNotifier_;

        ItemHandler itemHandler_;
        ItemNotifier itemNotifier_;

    private:
        friend AttackHandler;
        friend MovementHandler;
        friend ItemHandler;
        std::queue< std::tuple<Soul*, Soul*, Attacks::Attack*> > 
            combatEvents_;
        std::queue< std::pair<Soul*, std::string> > movementEvents_;
        std::queue< std::tuple<Soul*, Item*, std::string> > itemEvents_;
};

#endif
  
