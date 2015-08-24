//====================
// Include Guard
#ifndef NOTIFIERS_HPP_INCLUDED
#define NOTIFIERS_HPP_INCLUDED

//====================
// Forward declared dependencies
class Soul;
class Attack;

//====================
// Included dependencies
#include <set>
#include "handlers.hpp"

//====================
// Class

class Notifier { 
    public:
        void notify();
        void regHandler(Handler* handler );
        void unregHandler(Handler* handler);

    private:
        std::set<Handler*> registeredHandlers_;
};

class CombatNotifier : public Notifier {
    private:
        Soul* attacker;
        Soul* defender;
        Attack* attack; 
};

#endif
