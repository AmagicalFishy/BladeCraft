// g++ -o linked list testing_linkedlist.cpp

#include "../lib/linkedlist.hpp"
#include <iostream>

using namespace std;

class kittens {
    public:
        static int catCount;
        kittens() { ++catCount; }
        void meow() { cout << "meow meow meow meow meow meow meow"; }
        void setCall(int number) { call = number; }
        void rollCall() { 
            cout << "cat " << call << " reporting in\n"; 
        };
    private:
        int call;
};

int kittens::catCount = 1;

int main() {
    // Create/Fill Linked List
    LinkedList<kittens> catList;
    kittens litter[10];
    //kittens biggerLitter[15];
    for (int ii = 0; ii < 10; ++ii) { 
        litter[ii].setCall(ii);
        catList.addObject(litter[ii]); 
    };

    // Check iterator
    LinkedList<kittens>::ListIterator box = catList.begin();
    while (box != catList.end()) {
        (*box).rollCall();
        ++box;
    };
    //cout << "\n";
    //while (&*--box) { 
    //    (*box).rollCall();
    //};

    //// Alter Linked List
    //catList.removeObject(5);
    //catList.removeObject(6);
    //catList.removeObject(3);
    //// catList.removeObject(100); // Testing remove error
    //cout << "\n";
    //int ii = 0;
    //while (&*++box) {
    //    (*box).rollCall();
    //};
    //cout << "\n";
    //while (&*--box) { 
    //    (*box).rollCall();
    //};

    //// Try second iterator
    //LinkedList<kittens>::ListIterator crate = catList.getIterator();
    //cout << "\n";
    //crate.begin()->rollCall();
    //crate.end()->rollCall();
    //cout << "\n";

    //catList.removeObject(3);
    //catList.removeObject(4);
    //for (int ii = 0; ii < 15; ++ii) {
    //    biggerLitter[ii].setCall(ii + 11);
    //    catList.addObject(biggerLitter[ii]);
    //};

    //while (&*++crate) {
    //     cout << "box cats first\n";
    //     (*++box).rollCall();
    //     cout << "then crate cats\n";
    //     (*crate).rollCall();
    //};

    //return 0;
    };
