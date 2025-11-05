#include <iostream>
using namespace std;

// Node class for linked list bucket
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Bucket class: handles insertion and clearing
class Bucket {
public:
    Node* head;
    Node* tail;

    Bucket() {
        head = nullptr;
    }

    // Insert element at end
    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail=newNode;
            return;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    // Remove all nodes (free memory)
    void clear() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// RadixSort class
class RadixSort {
private:
    // Get maximum number to know digit count
    int getMax(int arr[], int n) {
        int mx = arr[0];
        for (int i = 1; i < n; i++)
            if (arr[i] > mx)
                mx = arr[i];
        return mx;
    }

public:
    // Main radix sort algorithm
    void sort(int arr[], int n) {
        int maxNum = getMax(arr, n);
        int exp = 1; // 1 = ones place, 10 = tens, etc.

        Bucket buckets[10]; // 10 buckets for digits 0–9

        while (maxNum / exp > 0) {
            // Clear previous buckets
            for (int i = 0; i < 10; i++)
                buckets[i].clear();

            // Place each number into the correct bucket
            for (int i = 0; i < n; i++) {
                int digit = (arr[i] / exp) % 10;
                buckets[digit].insert(arr[i]);
            }

            // Collect back into array
            int idx = 0;
            for (int i = 0; i < 10; i++) {
                Node* temp = buckets[i].head;
                while (temp != nullptr) {
                    arr[idx++] = temp->data;
                    temp = temp->next;
                }
            }

            exp *= 10; // Move to next digit
        }
    }

    // Utility function to print array
    void printArray(int arr[], int n) {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// Main function
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    RadixSort sorter;

    cout << "Original array: ";
    sorter.printArray(arr, n);

    sorter.sort(arr, n);

    cout << "Sorted array: ";
    sorter.printArray(arr, n);

    return 0;
}
