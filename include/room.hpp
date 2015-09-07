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
class World;

//====================
// Included dependencies
#include <set>
#include <string>
#include <unordered_map>
#include "command.hpp"

//====================
// Class
class Room {
    public:
        static int roomSerialCounter; // Counter of room serial numbers
        Room(std::array<int, 3> ID);
        ~Room();
        void initialize(std::string type, std::string name,
                std::string description);
        InfoModule* getInfo();
        void insert(Soul* soul);
        void insert(Item* item);
        void remove(Soul* soul);
        void remove(Item* item);
        void link(Room* toLink, std::string direction);
        Room* getRoom();
        Room* getRoom(std::string direction);
        std::array<int, 3> getID();

    private:
        friend World;
        friend MovementHandler;
        friend bool Commands::parseCommand(Soul* playerSoul, 
                std::string command);
        Room();
        std::unordered_map< std::string, Room*> linkedRooms_;
        std::set<Soul*> soulsInRoom_;
        std::set<Item*> itemsInRoom_;
        InfoModule* info_;
        std::array<int, 3> ID_;
};
        
#endif

