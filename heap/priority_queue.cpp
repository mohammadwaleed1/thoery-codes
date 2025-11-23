#include <iostream>
using namespace std;

// ====================== Node Class ======================
class Node {
public:
    int value;
    int priority;
    Node* next;

    // Constructor
    Node(int val, int pri) {
        value = val;
        priority = pri;
        next = nullptr;
    }
};

// ================= Priority Queue Class =================
class PriorityQueue {
private:
    Node* front;   // Head of the linked list (highest priority)

public:
    // Constructor
    PriorityQueue() {
        front = nullptr;
    }

    // Destructor (frees memory)
    ~PriorityQueue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Insert element into priority queue
    void insert(int value, int priority) {
        Node* newNode = new Node(value, priority);

        // Case 1: Queue empty OR new node has higher priority than front
        if (front == nullptr || priority > front->priority) {
            newNode->next = front;
            front = newNode;
        }
        else {
            // Find correct sorted position
            Node* current = front;
            while (current->next != nullptr && current->next->priority >= priority) {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Remove highest priority element
    void remove() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;
    }

    // Get value of highest priority element
    int peek() const {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->value;
    }

    // Print the entire priority queue
    void printQueue() const {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* current = front;
        while (current != nullptr) {
            cout << "(" << current->value << ", P:" << current->priority << ") ";
            current = current->next;
        }
        cout << endl;
    }
};

// ======================== MAIN ==========================
int main() {
    PriorityQueue pq;

    pq.insert(10, 3);
    pq.insert(20, 5);
    pq.insert(30, 1);
    pq.insert(25, 4);

    cout << "Priority Queue after insertions:" << endl;
    pq.printQueue();

    cout << "Top element (peek): " << pq.peek() << endl;

    pq.remove();
    cout << "After removing highest priority:" << endl;
    pq.printQueue();

    return 0;
}
