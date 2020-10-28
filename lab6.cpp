#include <iostream>
#include "MaxHeap.h"
using namespace std;

/**
 * An enum data type that can be used in the MaxHeap.
 * It represents different priority levels
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
void testEnqueue(MaxHeap<T> &m, T value, T max) {
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
void testDequeue(MaxHeap<T> &m, T max) {
    cout << "Dequeue  = " << m.dequeue() << " (expect " << max << ")" << endl;
}

/**
 * Tests all-at-once ctor and heapsort for int MaxHeaps
 * @param data array of ints
 * @param size of int array
 */
template<typename T>
void testCtor(T *data, int size) {
    cout << "testing all-at-once ctor: " << endl;
    MaxHeap<T> m(data, size);
    while (!m.empty()) {
        cout << m.dequeue() << " ";
    }
    cout << " (expect descending order)" << endl << endl;
}

template<typename T>
void testHeapsort(T *data, int size) {
    cout << "testing heapsort: " << endl;
    MaxHeap<T>::heapsort(data, size);
    for (int i =0; i < size; i++){
        cout << data[i] << " ";
    }
    cout << " (expect ascending order)" << endl << endl;
}


/**
 * Main entry to test MaxHeap methods
 * @return 0
 */
int main() {
    // TEST INT
    // test enqueue and dequeue
    MaxHeap<int> i;
    cout << "Testing int MaxHeap: " << endl;
    testEnqueue(i, 6, 6);
    testDequeue(i, 6);
    testEnqueue(i, 18, 18);
    testEnqueue(i, 15, 18);
    cout << endl;
    // test all-at-once ctor
    int dataI[] = {15, 19, 3, 7, 19, 12, 6, 1};
    testCtor(dataI, 8);
    //test heapsort
    testHeapsort(dataI, 8);
    cout << endl << endl;

    // TEST DOUBLE
    // test enqueue and dequeue
    MaxHeap<double> d;
    cout << "Testing double MaxHeap: " << endl;
    testEnqueue(d, 3.2, 3.2);
    testDequeue(d, 3.2);
    testEnqueue(d, 12.6, 12.6);
    testEnqueue(d, 12.5, 12.6);
    cout << endl;
    // test all-at-once ctor
    double dataD[] = {15.9, 19.1, 3.4, 7.8, 19.8, 12.6, 6.2, 1.3};
    testCtor(dataD, 8);
    //test heapsort
    testHeapsort(dataD, 8);
    cout << endl << endl;

    // TEST IMPORTANCE
    // test enqueue and dequeue
    MaxHeap<Importance> imp;
    cout << "Testing Importance MaxHeap: " << endl;
    testEnqueue(imp, HARDLY, HARDLY);
    testEnqueue(imp, SOMEWHAT, SOMEWHAT);
    testEnqueue(imp, BLEH, SOMEWHAT);
    testEnqueue(imp, UNIMPORTANT, SOMEWHAT);
    testEnqueue(imp, VERY, VERY);
    testEnqueue(imp, SOMEWHAT, VERY);
    cout << endl << endl;
    // test all-at-once ctor
    Importance dataImp[] = {BLEH, HARDLY, VERY, VERY,
                            SOMEWHAT, VERY, BLEH, UNIMPORTANT};
    testCtor(dataImp, 8);
    // test heapsort
    testHeapsort(dataImp, 8);




    return 0;
};


