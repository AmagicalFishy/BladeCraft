#include <iostream>
#include "headerlist.hpp"

using namespace std;

int main() {
    bool game_running = true;
    string mode = "command";
    string command = "";

    // Initialize game!
    CommandMode Command = CommandMode();
    ActionMode Action = ActionMode();

    // Create stuff
    Character protagonist = Character();
    Character monster = Character();
    Item sword = Item(20.0, "steel", "Sword");

    return 0;
};
