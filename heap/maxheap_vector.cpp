#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> v;

    // Heapify-up after insertion
    void heapifyUp(int child) {
        int parent = (child - 1) / 2;

        while (child > 0 && v[child] > v[parent]) {
            swap(v[child], v[parent]);
            child = parent;
            parent = (child - 1) / 2;
        }
    }

    // Heapify-down after pop
    void heapifyDown(int parent) {
        int size = v.size();

        while (true) {
            int leftChild = 2 * parent + 1;
            int rightChild = 2 * parent + 2;
            int largest = parent;

            if (leftChild < size && v[leftChild] > v[largest])
                largest = leftChild;

            if (rightChild < size && v[rightChild] > v[largest])
                largest = rightChild;

            if (largest == parent)
                break;

            swap(v[parent], v[largest]);
            parent = largest;
        }
    }

public:
    // Insert value into heap
    void push(int val) {
        v.push_back(val);
        heapifyUp(v.size() - 1); // child = last index
    }

    // Remove and return max
    int pop() {
        if (v.empty()) {
            cout << "Heap is empty!\n";
            return -1;
        }

        int rootVal = v[0];
        v[0] = v.back();
        v.pop_back();

        if (!v.empty()) {
            heapifyDown(0); // parent = root
        }

        return rootVal;
    }

    // Return max without removing
    int peek() {
        if (v.empty()) return -1;
        return v[0];
    }

    // Print heap array
    void printHeap() {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    // Return current size
    int getSize() {
        return v.size();
    }
};

// ----------------------------
// Example usage
// ----------------------------
int main() {
    MaxHeap heap;

    heap.push(40);
    heap.push(20);
    heap.push(50);
    heap.push(10);
    heap.push(30);

    cout << "Heap elements: ";
    heap.printHeap();

    cout << "Pop max: " << heap.pop() << endl;
    cout << "Heap after pop: ";
    heap.printHeap();

    cout << "Peek max: " << heap.peek() << endl;

    return 0;
}
