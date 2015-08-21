//====================
// Include Guard
#ifndef SOUL_HPP_INCLUDED
#define SOUL_HPP_INCLUDED

//====================
// Forward declared dependencies
//

class World;
class Item;

//====================
// Included dependencies
#include <map>
#include <string>

//====================
// Class
class Soul
{
    public:
        Soul(World* world);
        Soul* target_;
        const std::map<std::string, int>* getAttributes();
        void target(Soul* newTarget);
        void deltaHP(signed int change);
        void weakAttack();
        std::map<std::string, int> attributes_;
    
    private:
        int maxHP_;
        World* theWorld_;
        std::array<Item*, 25> inventory_;


};

#endif

