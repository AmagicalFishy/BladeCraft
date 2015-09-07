//====================
// Include Guard
#ifndef INFO_HPP_INCLUDED
#define INFO_HPP_INCLUDED

//====================
// Forward declared dependencies
//====================
// Included dependencies
#include <string>

//====================
// Info class

class InfoModule {
    public:
        InfoModule(std::string type, std::string name,
                std::string description);
        InfoModule(std::string type, std::string name,
                std::string description, std::string display);

        std::string getType();
        std::string getName();
        std::string getDescription();
        std::string getDisplay();
        
    private:
        std::string type_;
        std::string name_;
        std::string description_;
        std::string display_;
};

#endif
