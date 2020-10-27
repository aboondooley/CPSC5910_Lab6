#include <iostream>
#include "MaxHeap.h"
using namespace std;

int main() {
    MaxHeap<int> m;
    cout << m.empty() << endl;
    cout << m.size() << endl;
    return 0;
}
