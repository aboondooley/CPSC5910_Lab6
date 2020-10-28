#include <iostream>
#include "MaxHeap.h"
using namespace std;

/**
 * An enum data type that can be used in the MaxHeap
 */
enum Importance {  // enum classes are like a set of integer constants
    VERY = 20, SOMEWHAT = 9, BLEH = 0, HARDLY = -3, UNIMPORTANT = -10
};
/**
 * Tests enqueue and peek - the client must know the maximum value in the
 * MaxHeap to test
 * @tparam T Any numeric type (including Importance)
 * @param m MaxHeap of type T to test
 * @param value the value of type T to add to MaxHeap
 * @param max the maximum value in the Heap - to be expected when peek is
 * called
 */
template<typename T>
void testEnqueue(MaxHeap<T> m, T value, T max) {
    m.enqueue(value);
    cout << "Peek  = " << m.peek() << " (expect " << max << ")" << endl;
}

/**
 * Tests dequeue - the client must know the maximum value in the MaxHeap to test
 * @tparam T Any numeric type (including Importance)
 * @param m MaxHeap of type T to test
 * @param max the maximum value in the Heap - to be expected when peek is
 * called
 */
template<typename T>
void testDequeue(MaxHeap<T> m, T max) {
    cout << "Dequeue  = " << m.dequeue() << " (expect " << max << ")" << endl;
}

/**
 * Tests all-at-once ctor and heapsort for int MaxHeaps
 * @param data array of ints
 * @param size of int array
 */
void testInt(int *data, int size) {

}

/**
 * Tests all-at-once ctor and heapsort for double MaxHeaps
 * @param data array of doubles
 * @param size of double array
 */
void testDouble(double *data, int size) {

}

/**
 * Tests all-at-once ctor and heapsort for Importance MaxHeaps
 * @param data array of Importances
 * @param size of the Importances array
 */
void testImportance(Importance *data, int size) {

}


/**
 * Main entry to test MaxHeap methods
 * @return 0
 */
int main() {
    MaxHeap<int> m;
    cout << m.empty() << endl;
    m.enqueue(6);


    // Construction and first enqueue would look like this:
    MaxHeap<Importance> test;
    test.enqueue(HARDLY);

    return 0;
};


