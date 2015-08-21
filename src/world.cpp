//====================
// Include Guard
#ifndef __WORLD_HPP_INCLUDED__
#define __WORLD_HPP_INCLUDED__ 

//====================
// Forward declared dependencies
//
class Soul;
class AttackHandler;

//====================
// Included dependencies

//====================
// Class
class World {
    public:
        World();
        ~World();
        void processAttack(Soul* attacker, Soul* target, 
                AttackType attackType);

    private:
        AttackHandler* attackHandlers_;

}TheWorld;
  
