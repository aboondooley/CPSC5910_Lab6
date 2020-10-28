//
// Created by Alie on 10/26/2020.
//

#ifndef LAB6_MAXHEAP_MAXHEAP_H
#define LAB6_MAXHEAP_MAXHEAP_H
#include <iostream>
#include <vector>

/**
 * The Maxheap template class is a priority queue that keeps the greatest
 * value on the top and the lowest values on the bottom.
 * The parent has to be greater than or equal to all of it's children and the
 * BST structure must be complete.
 * Clients can construct an empty MaxHeap or create one with an array of data.
 * They can peek at the top value as well as pop it off. They can add values,
 * check if the MaxHeap is empty, and sort the MaxHeap into ascending order.
 * @tparam T Numeric value type that can be used in the MaxHeap
 */
template<typename T>
class MaxHeap {
private:
    std::vector<T> data;

    /**
     * Moves a value up in the Maxheap until it reaches it's appropriate spot
     * (greater than or equal to all of it's children)
     * Used in enqueue()
     * @param index the value ot move up
     */
    void percolateUp(int index) {
        if (index > 0){
            int p = parent(index);
            if (data[index] > data[p]){
                std::swap(data[index], data[p]);
                percolateUp(p); // this is now where index is
            }
        }
    }

    /**
     * Moves a value down in the heap until it reaches it's appropriate spot
     * (greater than or equal to all of it's children)
     * Used in dequeue()
     * @param index the value to move down
     */
    void percolateDown(int index) {
        if (hasLeft(index)) {
            int child = left(index);
            if (hasRight(index)) {
                int r = right(index);
                if (data[r] > data[child]) {
                    child = r;
                }
            }
            if (data[child] > data[index]) {
                std::swap(data[index], data[child]);
                percolateDown(child); // this is now where index is
            }
        }
    }

    /**
     * Arranges the values in the MaxHeap so that it aligns with the
     * definition of a MaxHeap (the parent has to be greater than or equal to
     * all of its children)
     */
    void heapify() {
        for (int index = data.size() / 2; index >= 0; index--){
            percolateDown(index);
        }
    }

    /**
     * Returns the index of the parent for any given child
     * @param index of the child
     * @return index of the parent
     */
    int parent(int index) {
        return (index - 1) / 2;
    }

    /**
    * Returns the index of the left child from any parent index
    * @param index parent index to get left child of
    * @return index of the left child
    */
    int left(int index) {
        return index * 2 + 1;
    }

    /**
     * Returns the index of the right child from any parent index
     * @param index parent index to get right child of
     * @return index of the right child
     */
    int right (int index) {
        return index * 2 + 2;
    }

    /**
     * Private helper to tell if a specific index has a left child
     * @param parent the parent index to test
     * @return true if there is a left child, false if not
     */
    bool hasLeft(int parent) const {
        return left(parent) < data.size();
    }

    /**
     * Private helper to tell if a specific index has a right child
     * @param parent the parent index to test
     * @return true if there is a right child, false if not
     */
    bool hasRight(int parent) const {
        return right(parent) < data.size();
    }

public:
    MaxHeap() {}

    /**
     * All at once constructor
     * @param initialDate
     * @param initialDataCount
     */
    MaxHeap(const T *initialDate, int initialDataCount) {
        for (int i = 0; i < initialDataCount; i++){
            data.push_back(initialDate[i]);
        }
        heapify();
    }

    /**
     *
     * @return
     */
    const T &peek() const {
        if (empty()){
            throw std::invalid_argument("empty queue");
        }
        return data[0];
    }

    /**
     *
     * @return
     */
    T dequeue() {
        int ret = peek();
        data[0] = data[data.size()];
        percolateDown(0);
        return ret;
    }

    /**
     *
     * @param value
     */
    void enqueue(T value) {
        data.push_back(value);
        percolateUp(data.size());
    }

    /**
     *
     * @return
     */
    bool empty() const {
        return data.size() == 0;
    }


    /**
     *
     * @param data
     */
    void heapsort(int *data) {
        MaxHeap<T> maxHeap(data, this->data.size());
        for (int i = this->data.size() - 1; i >= 0; i--) {
            data[i] = maxHeap.dequeue();
        }
    }
};


#endif //LAB6_MAXHEAP_MAXHEAP_H
