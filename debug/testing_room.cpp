#include <iostream>
#include "room.hpp"

using namespace std;

class kittens {
    public:
        static int catCount;
        kittens() { ++catCount; }
        void setCall(int number) { call = number; }
        void rollCall() { 
            cout << "cat " << call << " reporting in\n"; 
        };
    private:
        int call;
};

int main() {
    Room room;
    cout << room.roomID_ << "\n";
    room.showDescription();
    cout << "\n";

    return 0;
};
