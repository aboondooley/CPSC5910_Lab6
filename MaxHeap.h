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

    void percolateUp(int index) {
        if (index > 0){

        }
    }

    void percolateDown(int index) {

    }

    void heapify(){
        for (int index = data.size() / 2; index >= 0; index--){
            percolateDown(index);
        }
    }

public:
    MaxHeap(){
        data = vector<T>(0);
    }

    /**
     * All at once constructor
     * @param initialDate
     * @param initialDataCount
     */
    MaxHeap(const T *initialDate, int initialDataCount){
        data = vector<T>(initialDataCount);
        for (int i = 0; i < initialDataCount; i++){
            data[i] = initialDate[i];
        }
        heapify();
    }

    const T &peek() const {
        if (empty()){
            throw std::invalid_argument("empty queue");
        }
        return data[0];
    }

    T dequeue(){

    }

    void enqueue(T value){
        data.push_back(value);
        percolateUp(data.size());
    }

    bool empty(){
        return data.size() == 0;
    }


};


#endif //LAB6_MAXHEAP_MAXHEAP_H
