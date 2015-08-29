#include <iostream>
#include "headers.hpp"

int main() {
    World* theWorld = new World;
    Room* firstRoom = new Room;
    Room*  secondRoom = new Room;

    firstRoom->link(secondRoom, "north");
    firstRoom->initialize("room", "The bedroom of an Inn",
            "This is a small, dimly lit, carpeted room."
            "");

    secondRoom->link(firstRoom, "south"); 
    secondRoom->initialize("room", "The hallway in the Inn",
            "Though sunlight shines through the windows, the Inn "
            "itself is completely silent; your footsteps and the "
            "creaking of the wood floor are its only sounds.");

    Equipment* sword = new Equipment("held", firstRoom);
    sword->setAttribute("str", 10);
    sword->setAttribute("def", 0);
    sword->initialize("sword", "Longsword", "A long sword");

    Equipment* shield = new Equipment("held", secondRoom);
    shield->setAttribute("str", 0);
    shield->setAttribute("def", 3);
    shield->initialize("shield", "Wooden Shield", 
            "A round, wooden shield");

    Equipment* armor = new Equipment("body", secondRoom);
    armor->setAttribute("str", 0);
    armor->setAttribute("def", 5);
    armor->initialize("armor", "Armor", "The torso part of a suit of "
            "armor");

    Equipment* helmet = new Equipment("helm", secondRoom);
    helmet->setAttribute("str", 0);
    helmet->setAttribute("def", 2);
    helmet->initialize("helmet", "Leather Helmet", "A leather helmet");

    Soul* soulOne = new Soul(theWorld, firstRoom);

    std::string command;
    bool runGame = true;

    while (runGame == true) { 
        std::cout << "Command: ";
        std::cin >> command; 

        if (command == "-1") { break; }
        if (command == "n") { soulOne->move("north"); }
        if (command == "s") { soulOne->move("south"); }
        if (command == "w") { soulOne->move("west"); }
        if (command == "e") { soulOne->move("east"); }
    };

    return 0;
};
