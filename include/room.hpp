//====================
// Include Guard
#ifndef ROOM_HPP_INCLUDED
#define ROOM_HPP_INCLUDED

//====================
// Forward declared dependencies
class InfoModule;
class Item;
class MovementHandler;
class Soul;

//====================
// Included dependencies
#include <set>
#include <string>
#include <map>

//====================
// Class
class Room {
    public:
        static int roomSerialCounter; // Counter of room serial numbers

        Room();
        ~Room();
        void initialize(std::string type, std::string name,
                std::string description);
        InfoModule* getInfo();
        void insert(Soul* soul);
        void insert(Item* item);
        void remove(Soul* soul);
        void remove(Item* item);
        void link(Room* toLink, std::string direction);
        Room* getRoom(std::string direction);


    private:
        friend MovementHandler;
        std::map<std::string, Room*> linkedRooms_;
        std::set<Soul*> soulsInRoom_;
        std::set<Item*> itemsInRoom_;
        InfoModule* info_;
        int ID_;
};
        
#endif

