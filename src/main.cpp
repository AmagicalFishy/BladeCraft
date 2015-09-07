#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
#include "headers.hpp"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"

int main() {
    // Create the World and the player's character (Soul)
    World* theWorld = new World;
        
    // Create all rooms
    std::unordered_map<std::string, Room*> rooms;
    FILE* roomFile = fopen("database/rooms.json", "r");
    char buffer[65536];
    rapidjson::FileReadStream roomStream(roomFile, 
            buffer, sizeof(buffer));
    rapidjson::Document allRooms;
    allRooms.ParseStream(roomStream);

    // Scroll through numbers and, if a room exists w/ that coord.,
    // create it and initialize it with information
    for (int ii = 0; ii <= 1; ++ii) { 
    for (int jj = 0; jj <= 1; ++jj) { 
    for (int kk = 0; kk <= 1; ++kk) { 
        std::string roomCoordStr =  std::to_string(ii) + "." + 
                                    std::to_string(jj) + "." +
                                    std::to_string(kk);
        const char* roomCoord = roomCoordStr.c_str();
        if (allRooms.HasMember(roomCoord)) {
                const rapidjson::Value& room = allRooms[roomCoord];
                std::array<int, 3> id = {ii, jj, kk};
                rooms[roomCoord] = new Room(id);
                rooms[roomCoord]->initialize(
                        "room", // The type of object is room
                        room["name"].GetString(), 
                        room["description"].GetString() 
                        );
        }
    }
    }
    }
    for (auto room = rooms.begin(); room != rooms.end(); ++room) {
        std::cout << (*room).first << ": " << 
        rooms[(*room).first]->getInfo()->getName() << '\n';
    }

    std::cout << '\n';
    // Link appropriate rooms
    for (auto room = rooms.begin(); room != rooms.end(); ++room) {
        std::array<int, 3> idArray = (*room).second->getID();

        std::map<std::string, std::string> directions;
        
        std::string hereStr = 
            std::to_string(idArray[0]) + "." +
            std::to_string(idArray[1]) + "." + 
            std::to_string(idArray[2]);

        const char* here = hereStr.c_str();

        std::string north = 
            std::to_string(idArray[0]) + "." +
            std::to_string(idArray[1] + 1) + "." + 
            std::to_string(idArray[2]);
        std::string east = 
            std::to_string(idArray[0] + 1) + "." + 
            std::to_string(idArray[1]) + "." + 
            std::to_string(idArray[2]);
        std::string south = 
            std::to_string(idArray[0]) + "." + 
            std::to_string(idArray[1] - 1) + "." + 
            std::to_string(idArray[2]);
        std::string west = 
            std::to_string(idArray[0] - 1) + "." + 
            std::to_string(idArray[1]) + "." + 
            std::to_string(idArray[2]);
        std::string up = 
            std::to_string(idArray[0]) + "." + 
            std::to_string(idArray[1]) + "." + 
            std::to_string(idArray[2] + 1);
        std::string down = 
            std::to_string(idArray[0]) + "." + 
            std::to_string(idArray[1]) + "." + 
            std::to_string(idArray[2] - 1);

        directions["north"] =  north;
        directions["east"] = east;
        directions["south"] = south;
        directions["west"] = west;
        directions["up"] = up;
        directions["down"] = down;

        for (rapidjson::Value::ConstValueIterator linkItr = 
                allRooms[here]["link"].Begin(); 
                linkItr != allRooms[here]["link"].End(); 
                ++linkItr) {
            std::string dir = (*linkItr).GetString();
            (*room).second->link( rooms[ directions[dir] ]->getRoom(), 
                    dir );

            std::cout << (*room).second->getInfo()->getName() << 
                " linked to " << 
                rooms[ directions[dir] ]->
                    getInfo()->getName() << '\n';
        }
    }
    
    bool runGame = true;
    std::string command;
    Soul* playerSoul = new Soul(theWorld, rooms["0.1.1"]->getRoom());
    playerSoul->move("south");

    while (runGame == true) { 

        std::cout << BOLDWHITE << "Command: " << BLUE;
        std::getline(std::cin, command);
        std::cout << RESET;
        
        runGame = Commands::parseCommand(playerSoul, command);

        std::cout << RED << "HP: " << RESET << playerSoul->HP_ << "\n";
    };

    return 0;
};
