//====================
// Include Guard
#ifndef HANDLERS_HPP_INCLUDED
#define HANDLERS_HPP_INCLUDED

//====================
// Forward declared dependencies
class Notifier;
class World;

//====================
// Included dependencies
#include <map>
#include <string>

//====================
// Class
class Handler {
    public:
        Handler(World* currentWorld);
        virtual void recieveNotification() = 0;
        void watchNotifier(Notifier* toWatch);
        void unwatchNotifier(Notifier* toUnwatch);


    protected:
        Notifier* watching_;
        World* currentWorld_;
};

class AttackHandler : public Handler {
    public:
        AttackHandler(World* currentWorld);
        void recieveNotification();
};

class MovementHandler : public Handler { 
    public:
        MovementHandler(World* currentWorld);
        void recieveNotification();
};

class ItemHandler : public Handler {
    public:
        ItemHandler(World* currentWorld);
        void recieveNotification();
};

#endif

