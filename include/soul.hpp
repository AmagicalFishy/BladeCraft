//====================
// Include Guard
#ifndef SOUL_HPP_INCLUDED
#define SOUL_HPP_INCLUDED

//====================
// Forward declared dependencies
class World;

//====================
// Included dependencies
#include <map>

//====================
// Class
class Soul {
    public:
        Soul();
        Soul(World* currentWorld); 
        void setWorld(World* currentWorld); 
        void setTarget(Soul* target);
        int getAttribute(std::string attribute);
        void weakAttack();
        int HP_;

    private:
        int maxHP_; 
        World* currentWorld_;
        Soul* target_;
        std::map<std::string, int> attributes_;
};

#endif

