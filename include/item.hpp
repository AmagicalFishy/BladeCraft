//====================
// Include Guard
#ifndef __ITEM_HPP_INCLUDED__
#define __ITEM_HPP_INCLUDED__

//====================
// Forward declared dependencies
// class material;

//====================
// Included dependencies
#include <string>

//====================
// Classes
class Item
{
    public: 
        Item();
        Item(float weight, std::string material, std::string name);

        void setName(std::string new_name);
        std::string getName();

        void setMaterial(std::string new_material);
        std::string getMaterial();

        void setWeight(float new_weight);
        float getWeight();

    private:
        float m_weight;
        std::string m_material;
        std::string m_name;
};

#endif

