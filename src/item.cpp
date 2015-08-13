#include "item.hpp"

Item::Item() {}
Item::Item(float weight, std::string material, std::string name) {
    m_weight = weight;
    m_material = material;
    m_name = name;
}

void Item::setName(std::string new_name) { m_name  = new_name; }
std::string Item::getName() { return m_name; }

void Item::setMaterial(std::string new_material) { 
    m_material  = new_material; 
}
std::string Item::getMaterial() { return m_material; }

void Item::setWeight(float new_weight) { m_weight  = new_weight; }
float Item::getWeight() { return m_weight; }

