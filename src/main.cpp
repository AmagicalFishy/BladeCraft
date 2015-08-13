#include <iostream>
#include "character_headers.hpp"
#include "item_headers.hpp"
#include "modes_headers.hpp"

using namespace std;

int main() {
    bool game_running = true;
    string mode = "command";
    string command = "";

    // Initialize game!
    CommandMode* Command = new CommandMode();
    ActionMode* Action = new ActionMode();

    // Create stuff
    Character* protagonist = new Character();
    Character* monster = new Character();
    Item* sword = new Item(20.0, "steel", "Sword");

    // Main game loop
    while (game_running == true) { 
        // Parse commands in command mode
        if (mode == "command"){
            cout << "Command: ";
            getline(cin, command);
            cout << "\n";
            Command->parseCommand(command);
        }

        // Perform actions in action mode
        if (mode == "action"){}
    }

    return 0;
}
