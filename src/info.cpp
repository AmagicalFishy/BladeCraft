#include "info.hpp"

InfoModule::InfoModule(int ID, std::string type, std::string name, 
        std::string description)
: ID_(ID), type_(type), name_(name), description_(description) {}

int InfoModule::getID() { return ID_; }
std::string InfoModule::getType() { return type_; }
std::string InfoModule::getName() { return name_; }
std::string InfoModule::getDescription() { return description_; }

