//
// Created by Alie on 10/26/2020.
//

#ifndef LAB6_MAXHEAP_MAXHEAP_H
#define LAB6_MAXHEAP_MAXHEAP_H
#include <iostream>
#include <vector>


template<typename T>
class MaxHeap {
private:
    std::vector<T> data;
    static const int ROOT = 0;

    void percolateUp(int index) {
        if (index > ROOT){
            int p = parent(index);
            if (data[index] > data[p]){
                swap(data[index], data[p]);
                percolateUp(p); // this is now where index is
            }
        }
    }

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
                swap(data[index], data[child]);
                percolateDown(child); // this is now where index is
            }
        }
    }

    void heapify() {
        for (int index = data.size() / 2; index >= 0; index--){
            percolateDown(index);
        }
    }

    int parent(int index) {
        return (index - 1) / 2;
    }

    int left(int index) {
        return index * 2 + 1;
    }

    int right (int index) {
        return index * 2 + 2;
    }

    bool hasLeft(int parent) const {
        return left(parent) < size();
    }

    bool hasRight(int parent) const {
        return right(parent) < size();
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

    const T &peek() const {
        if (empty()){
            throw std::invalid_argument("empty queue");
        }
        return data[ROOT];
    }

    T dequeue() {
        int ret = peek();
        data[ROOT] = data[data.size()];
        percolateDown(ROOT);
        return ret;
    }

    void enqueue(T value) {
        data.push_back(value);
        percolateUp(data.size());
    }

    bool empty() const {
        return data.size() == 0;
    }

    int size() const {
        return data.size();
    }
};


#endif //LAB6_MAXHEAP_MAXHEAP_H
