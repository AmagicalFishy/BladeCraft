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

class Item {
    public: 
        static int itemSerialCounter;
        Item();
        Item(int uniqueID, int itemID);
        int getID();

        float weight_;
        std::string material_;
        std::string name_;

    private:
        int uniqueID;
        int itemID;
        int[] enhancements;

};

#endif

