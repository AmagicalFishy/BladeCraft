#include "../include/linkedlist.hpp"

using namespace std;

class poop {
    public:
        int toilet;
        poop() {};
        poop(int shit) { toilet = shit; };
};

poop butt = poop(4);
poop butt2 = poop(5);

int main() {
    LinkedList<poop> testList(butt);
    testList.addObject(butt2);

    ListIterator<poop> fuck = testList.getIterator();
    cout << fuck.next().toilet << "\n";    
    cout << fuck.next().toilet << "\n";
    cout << fuck.next().toilet << "\n";
    cout << fuck.next().toilet << "\n";
    cout << fuck.next().toilet << "\n";
    cout << fuck.next().toilet << "\n";
    cout << fuck.next().toilet << "\n";
    cout << fuck.next().toilet << "\n";

    return 0;
}
