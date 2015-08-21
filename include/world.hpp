//====================
// Include Guard
#ifndef WORLD_HPP_INCLUDED
#define WORLD_HPP_INCLUDED

//====================
// Forward declared dependencies


class Soul;
class Attack;

//====================
// Included dependencies

//====================
// Class
class World {
    public:
        void processAttack(Soul* attacker, Soul* target, 
                Attack attackType);

    private:

};

#endif
  
