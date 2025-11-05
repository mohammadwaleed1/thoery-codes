#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Linked list class with head and tail
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at end using tail pointer
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {       // list is empty
            head = tail = newNode;
        } else {           // append at end
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Clear all nodes
    void clear() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr; // reset tail
    }
};

// Get maximum number in array
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx) mx = arr[i];
    return mx;
}

// Radix Sort
void radixSort(int arr[], int n) {
    int maxNum = getMax(arr, n);
    int exp = 1; // digit place

    LinkedList buckets[10];

    while (maxNum / exp > 0) {
        // Place elements into buckets
        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / exp) % 10;
            buckets[digit].insert(arr[i]);
        }

        // Collect numbers back into array
        int idx = 0;
        for (int i = 0; i < 10; i++) {
            Node* temp = buckets[i].head;
            while (temp!=nullptr) {
                arr[idx++] = temp->data;
                temp = temp->next;
            }
            buckets[i].clear();
        }

        exp *= 10;
    }
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    radixSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
