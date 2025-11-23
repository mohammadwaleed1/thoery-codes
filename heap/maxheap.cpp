#include <iostream>
using namespace std;

class MaxHeap {
public:
    int arr[1000];  // fixed-size array
    int size;       // current number of elements

    MaxHeap() {
        size = 0;
    }

    // ----------------------------
    // PUSH / INSERT
    // ----------------------------
    void push(int val) {
        arr[size] = val;      // insert at last index
        int index = size;
        size++;

        heapifyUp(index);     // fix heap property upwards
    }

    // heapify-up logic for max-heap
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;

        // while index > 0 and child > parent
        while (parent>=0 > 0 && arr[index] > arr[parent]) {
            // swap child and parent
            int temp = arr[index];
            arr[index] = arr[parent];
            arr[parent] = temp;

            // move index to parent
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    // ----------------------------
    // POP / DELETE ROOT
    // ----------------------------
    int pop() {
        if (size == 0) {
            cout << "Heap empty!\n";
            return -1;
        }

        int rootVal = arr[0];         // store max element

        arr[0] = arr[size - 1];       // move last element to root
        size--;                       // remove last element

        heapifyDown(0);               // restore heap property

        return rootVal;
    }

    // heapify-down logic for max-heap
    void heapifyDown(int index) {
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            // check left child
            if (left < size && arr[left] > arr[largest])
                largest = left;

            // check right child
            if (right < size && arr[right] > arr[largest])
                largest = right;

            // if parent already largest → stop
            if (largest == index)
                break;

            // swap parent with largest child
            int temp = arr[index];
            arr[index] = arr[largest];
            arr[largest] = temp;

            // move down
            index = largest;
        }
    }

    // ----------------------------
    // PEEK ROOT
    // ----------------------------
    int peek() {
        if (size == 0) return -1;
        return arr[0];
    }

    // ----------------------------
    // PRINT HEAP
    // ----------------------------
    void printHeap() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// ----------------------------
// Example Usage
// ----------------------------
int main() {
    MaxHeap heap;

    heap.push(1);
    heap.push(4);
    heap.push(2);
    heap.push(5);
    heap.push(3);

    cout << "Heap elements: ";
    heap.printHeap();

    // cout << "Pop max: " << heap.pop() << endl;
    // cout << "Heap after pop: ";
    // heap.printHeap();

    // cout << "Peek max: " << heap.peek() << endl;

    return 0;
}
