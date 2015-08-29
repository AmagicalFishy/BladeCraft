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
        InfoModule(int ID, std::string type, std::string name,
                std::string description);
        int getID();
        std::string getType();
        std::string getName();
        std::string getDescription();
        
    private:
        int ID_;
        std::string type_;
        std::string name_;
        std::string description_;
};

#endif
