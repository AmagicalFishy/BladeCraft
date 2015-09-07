#include <sstream>
#include <iostream>
#include "headers.hpp"

// Function that fetches object pointer by name
template<typename T> T* Commands::fetchObject(std::string type, 
        std::set<T*>* objectSet) { 
    //unsigned int matches = 0;
    for (auto object = objectSet->begin();
            object != objectSet->end(); ++object) {
        if ((*object)->getInfo()->getType() == type) {
            return (*object);
            //++matches;
        }
    }
    return nullptr;
}

// Splits command line into individual words 
std::vector<std::string> Commands::split(const std::string command, 
    char delimiter) {
    std::vector<std::string> words;
    std::stringstream commandStream(command);
    std::string word;
    while (std::getline(commandStream, word, delimiter)) {
        words.push_back(word);
    }
    return words;
}

// Parse commands: See what word 1 is, then, if necessary,
// see what words 2 and 3 are
bool Commands::parseCommand(Soul* playerSoul, std::string command) {
    //bool nounFlag = false;
    //bool verbFlag = false;

    std::vector<std::string> words = Commands::split(command, ' ');
    // Quit
    if (words[0] == "-q") { return false; }

    // Directional commands
    if (words[0] == "n") { playerSoul->move("north"); }
    if (words[0] == "e") { playerSoul->move("east"); }
    if (words[0] == "s") { playerSoul->move("south"); }
    if (words[0] == "w") { playerSoul->move("west"); }
    if (words[0] == "u") { playerSoul->move("up"); }
    if (words[0] == "d") { playerSoul->move("down"); }

    // Item commands
    // Get item from room into inventory
    if (words[0] == "get") { 
        if (words.size() < 2) { 
            std::cout << "\nGet... what?\n\n"; 
        }
        else{    
            Item* item = fetchObject<Item>(words[1], 
                    &(playerSoul->currentRoom_->itemsInRoom_));
            playerSoul->get(item);
            std::cout << "You put " << item->getInfo()->getName() << 
                " into your inventory.\n";
        }
    }

    // Look at inventory
    if (words[0] == "inv") {
        std::cout << "\nInventory: \n";
        for (auto items = playerSoul->inventory_.begin(); 
                items != playerSoul->inventory_.end(); ++items) {
            std::cout << "- " << (*items)->getInfo()->getName() << 
                "\n";
        }
        std::cout << "\n";
    }

    // Attack something
    if (words[0] == "att") {
        if (words.size() < 2) { 
            std::cout << "\nHow strong should the attack be, and "
                "what are you attacking?\n\n";
        }
        else { 
            playerSoul->setTarget(fetchObject<Soul>(words[1], 
                    &(playerSoul->currentRoom_->soulsInRoom_)));
            playerSoul->weakAttack();
        }
    }

    return true;
}




    
