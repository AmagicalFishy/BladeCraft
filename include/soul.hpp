//====================
// Include Guard
#ifndef __SOUL_HPP_INCLUDED__
#define __SOUL_HPP_INCLUDED__ 

//====================
// Forward declared dependencies
//
class World;
class Item;
class AttackType;

//====================
// Included dependencies
#include <map>
#include <string>

//====================
// Class
class Soul
{
    public:
        Soul();
        Soul* target_;
        void deltaHP(signed int change);
        void weakAttack();
    
    private:
        World& theWorld_;
        int maxHP_;
        std::map<std::string, int> attributes_;
        std::array<Item*, 25> inventory_;


};

#endif

