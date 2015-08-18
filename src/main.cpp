#include <iostream>
#include <string>
#include <array>
#include "headerlist.hpp"

int main() {
    std::string mode = "command";
    std::string command = "";

    // Initialize game!
    // Create stuff
    std::array<int, 2> swordStats = {{5, 0}};
    std::array<int, 2> shieldStats = {{0, 2}};
    std::array<int, 2> armorStats = {{0, 3}};
    Item sword("Sword", swordStats);
    Item shield("Shield", shieldStats);
    Item armor("Armor", armorStats);
    Room room;

    // Test stuff!
    room.addItem(shield);
    room.addItem(sword);
    room.addItem(armor);
    LinkedList<Item>::ListIterator roomItems = room.itemsInThisRoom_.begin();

    while (roomItems != room.itemsInThisRoom_.end()) {
        std::map<std::string, int> stats;
        stats = (*roomItems).getStats();
        std::cout << "Item: " << (*roomItems).name_ << "\n";
        std::cout << "Stats\n";
        for (auto stat : stats) {
          std::cout << stat.first << ": " << stat.second << "\n";
        };
        std::cout << "\n";
        ++roomItems;
    };

    return 0;
};
