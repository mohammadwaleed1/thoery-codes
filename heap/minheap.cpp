#include <iostream>
using namespace std;

class MinHeap {
public:
    int arr[1000];
    int size;

    MinHeap() {
        size = 0;
    }

    // ----------------------------
    // PUSH
    // ----------------------------
    void push(int val) {
        arr[size] = val;
        int index = size;
        size++;

        heapifyUp(index);
    }

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;

        // while child < parent
        while (parent >= 0 && arr[index] < arr[parent]) {

            int temp = arr[index];
            arr[index] = arr[parent];
            arr[parent] = temp;

            index = parent;
            parent = (index - 1) / 2;
        }
    }

    // ----------------------------
    // POP
    // ----------------------------
    int pop() {
        if (size == 0) {
            cout << "Heap empty!\n";
            return -1;
        }

        int rootVal = arr[0];

        arr[0] = arr[size - 1];   // move last to root
        size--;

        heapifyDown(0);

        return rootVal;
    }

    void heapifyDown(int index) {
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            // if left child smaller than parent
            if (left < size && arr[left] < arr[smallest])
                smallest = left;

            // if right child smaller than current smallest
            if (right < size && arr[right] < arr[smallest])
                smallest = right;

            // if parent already smallest → done
            if (smallest == index)
                break;

            // swap with smaller child
            int temp = arr[index];
            arr[index] = arr[smallest];
            arr[smallest] = temp;

            index = smallest;
        }
    }

    int peek() {
        if (size == 0) return -1;
        return arr[0];
    }
};
