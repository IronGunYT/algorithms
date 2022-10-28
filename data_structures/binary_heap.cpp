/****************************************************************
 * @file
 * @brief Binary Heap Data Structure
 * @details
 * Binary Heap is a data structure, that allows answering range queries.
 * Operation: remove maximum or minimum element in a set of elements in O(logn)
 *
 * ### Complexity
 *
 * Build : O(n)
 * Range Query : O(logn)
 * Add element : O(logn)
 * Edit element : O(logn)
 * Remove max/min element : O(logn)
 * Space Complexity : O(1)
****************************************************************/

#include <iostream>
#include <vector>
#include <cmath>

template <typename T>
class BinaryHeap{
    std::vector<T> heap;
    int n;  // size of input array
    bool (*func)(T, T);  // function to use for range queries

    /**
     * @brief Restoring Heap Properties
     * @param i - index of element to restore heap properties
     */
    void heapify(int i){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if(left < n && func(heap[left], heap[i]))
            largest = left;
        if(right < n && func(heap[right], heap[largest]))
            largest = right;
        if(largest != i){
            std::swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    /**
     * @brief Fills the heap with the values of the input array
     * @param arr
     */
    void build(std::vector<T> &arr){
        for(int i = 0; i < n; i++)
            heap[i] = arr[i];
        for(int i = n / 2 - 1; i >= 0; i--)
            heapify(i);
    }

public:
    /**
     * @brief Constructor
     * @param arr - input array
     * @param f - function to use for comparision queries
     */
    BinaryHeap(std::vector<T> &arr, bool (*f)(T, T)){
        n = arr.size();
        func = f;
        heap.resize(n);
        build(arr);
    }

    /**
     * @brief Add element to the heap
     * @param val - element to add
     */
    void add(T val){
        heap.push_back(val);
        n++;
        int i = n - 1;
        while(i != 0 && func(heap[i], heap[(i - 1) / 2])){
            std::swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    /**
     * @brief Remove element from the heap
     * @param i - index of element to remove
     */
    void remove(int i){
        heap[i] = heap[n - 1];
        heap.pop_back();
        n--;
        heapify(i);
    }

    /**
     * @brief Edit element in the heap
     * @param i - index of element to edit
     * @param val - new value of element
     */
    void replace(int i, T val){
        heap[i] = val;
        heapify(i);
    }

    /**
     * @brief Get lead element in the heap
     * @returns lead element in the heap
     */
    T get(){
        return heap[0];
    }

    /**
     * @brief Get size of the heap
     * @returns size of the heap
     */
    int size(){
        return n;
    }

    /**
     * @brief Get heap
     * @returns heap
     */
    std::vector<T> get_heap(){
        return heap;
    }

    /**
     * @brief Print heap
     */
    void print(){
        for(int i = 0; i < n; i++)
            std::cout << heap[i] << " ";
        std::cout << std::endl;
    }
};

int main(){
    std::cout << "Heap test" << std::endl;
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BinaryHeap<int> heap(arr, [](int a, int b){return a > b;});
    heap.print();
    heap.add(11);
    heap.print();
    heap.remove(0);
    heap.print();
    heap.replace(0, 0);
    heap.print();
    return 0;
}
