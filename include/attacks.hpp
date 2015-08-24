//====================
// Include Guard
#ifndef ATTACKS_HPP_INCLUDED
#define ATTACKS_HPP_INCLUDED

//====================
// Forward declared dependencies
class Soul;

//====================
// Included dependencies

//====================
// Class

namespace Attacks {

    class Attack {
        public:
            Attack(Soul* attacker, float damageMultiplier);
            int getDamage();

        private:
            int damage_;
    };

}
    
#endif

