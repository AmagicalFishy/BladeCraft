#include "info.hpp"

InfoModule::InfoModule(std::string type, std::string name, 
        std::string description)
: type_(type), name_(name), description_(description),
display_("None") {}

InfoModule::InfoModule(std::string type, std::string name, 
        std::string description, std::string display)
: type_(type), name_(name), description_(description),
  display_(display) {}

std::string InfoModule::getType() { return type_; }
std::string InfoModule::getName() { return name_; }
std::string InfoModule::getDescription() { return description_; }
std::string InfoModule::getDisplay() { return display_; }

