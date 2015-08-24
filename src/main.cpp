#include <iostream>
#include "headerlist.hpp"

//scanf for 

int main() {

   // // Preliminary Testing
   // // Soul Testing:
   // std::cout << "Soul Testing:\n";

   // Soul* soulOne = new Soul();
   // Soul* soulTwo = new Soul(); 
   // std::cout << "Soul 1's Str: " << soulOne->getAttribute("str") << 
   //     "\n";
   // std::cout << "Soul 2's HP: " << soulTwo->HP_ << "\n";
   // std::cout << "Setting Soul 1's target to Soul 2...\n"; 
   // soulOne->setTarget(soulTwo);
   // std::cout << "Success.\n\n";

   // // World Testing:
   // std::cout << "World Testing:\n";

   // World* theWorld = new World();
   // std::cout << "Setting both souls' world...\n";
   // soulOne->setWorld(theWorld);
   // soulTwo->setWorld(theWorld);
   // std::cout << "Success.\n";

   // // Attacks Testing:
   // std::cout << "Attacks Testing:\n";

   // Attacks::Attack* testAttack = new Attacks::Attack(soulOne, .75);
   // std::cout << "Direct test attack's damage for Soul 1: " << 
   //     testAttack->getDamage() << "\n";
   // 
   // // Handlers Testing & Notifiers Testing:
   // std::cout << "Handlers Testing & Notifiers Testing:\n";

   // std::cout << "Soul 2's HP: " << soulTwo->HP_ << "\n";
   // std::cout << "Soul 1 performing weak attack on Soul 2: \n";
   // soulOne->weakAttack();
   // std::cout << "Soul 2's HP: " << soulTwo->HP_ << "\n";
   // std::cout << "Success.\n"; 
  
    //Basic Combat Testing 
    World* theWorld = new World();
    Soul* soulOne = new Soul(theWorld);
    Soul* soulTwo = new Soul(theWorld);
    soulOne->setTarget(soulTwo);

    std::cout << "Soul 2's HP: " << soulTwo->HP_ << "\n";
    soulOne->weakAttack();
    std::cout << "Soul 2's HP: " << soulTwo->HP_ << "\n";
    soulOne->weakAttack();
    std::cout << "Soul 2's HP: " << soulTwo->HP_ << "\n";
    soulOne->weakAttack();
    std::cout << "Soul 2's HP: " << soulTwo->HP_ << "\n";
    soulOne->weakAttack();
    std::cout << "Soul 2's HP: " << soulTwo->HP_ << "\n";
    soulOne->weakAttack();
    std::cout << "Soul 2's HP: " << soulTwo->HP_ << "\n";
    soulOne->weakAttack();
    std::cout << "Soul 2's HP: " << soulTwo->HP_ << "\n";
    soulOne->weakAttack();
    std::cout << "Soul 2's HP: " << soulTwo->HP_ << "\n";
    soulOne->weakAttack();
    std::cout << "Soul 2's HP: " << soulTwo->HP_ << "\n";

    soulTwo->setTarget(soulOne);
    soulTwo->weakAttack();
    soulOne->weakAttack();
    soulTwo->weakAttack();
    soulTwo->weakAttack();
    soulOne->weakAttack();
    soulTwo->weakAttack();
    soulTwo->weakAttack();
    soulOne->weakAttack();
    soulTwo->weakAttack();
    soulOne->weakAttack();
    soulTwo->weakAttack();
    soulTwo->weakAttack();

    std::cout << "\n";
    std::cout << "Soul 1's HP: " << soulOne->HP_ << "\n";
    std::cout << "Soul 2's HP: " << soulTwo->HP_ << "\n";



    return 0;
};
