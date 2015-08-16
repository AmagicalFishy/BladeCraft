#include "item.hpp"
Item::itemSerialCounter = 0;
Item::Item() { 
    uniqueID = itemSerialCounter++;
    enhancements[5];
};
