#include <iostream>
#include "MaxHeap.h"
using namespace std;

int main() {
    MaxHeap<int> m;
    cout << m.empty() << endl;
    cout << m.size() << endl;
    //TODO update so it works with the enum:
    /*
     * enum Importance {  // enum classes are like a set of integer constants
    VERY = 20, SOMEWHAT = 9, BLEH = 0, HARDLY = -3, UNIMPORTANT = -10
};

// Construction and first enqueue would look like this:
MaxHeap<Importance> test;
test.enqueue(HARDLY);
     */
    return 0;
}
