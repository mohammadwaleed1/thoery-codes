#include <iostream>
using namespace std;

// Node for linked list
struct Node {
    int key;
    Node* next;
    Node(int k) : key(k), next(nullptr) {}
};

// Hash Table class
class HashTable {
    static const int TABLE_SIZE = 10;  // size of hash table
    Node* table[TABLE_SIZE];

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = nullptr;
    }

    // Hash function
    int hash(int key) {
        return key % TABLE_SIZE;
    }

    // Insert key
    void insert(int key) {
        int index = hash(key);
        Node* newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;  // insert at head
    }

    // Search key
    bool search(int key) {
        int index = hash(key);
        Node* curr = table[index];
        while (curr) {
            if (curr->key == key)
                return true;
            curr = curr->next;
        }
        return false;
    }

    // Delete key
    void remove(int key) {
    int index = hash(key);
    Node* curr = table[index];

    // If the list is empty, nothing to delete
    if (!curr) return;

    // If head node needs to be deleted
    if (curr->key == key) {
        table[index] = curr->next;
        delete curr;
        return;
    }

    // For other nodes
    Node* temp = curr;
    while (temp->next) {
        if (temp->next->key == key) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            return;
        }
        temp = temp->next;
    }
}


    // Display hash table
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Bucket " << i << ": ";
            Node* curr = table[i];
            while (curr) {
                cout << curr->key << " -> ";
                curr = curr->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht;

    // Insert some keys
    ht.insert(15);
    ht.insert(25);
    ht.insert(35);
    ht.insert(7);
    ht.insert(17);

    ht.display();

    cout << "\nSearch 25: " << (ht.search(25) ? "Found" : "Not Found") << endl;
    cout << "Search 10: " << (ht.search(10) ? "Found" : "Not Found") << endl;

    // Delete keys
    cout << "\nDeleting 25...\n";
    ht.remove(25);
    cout << "Deleting 7...\n";
    ht.remove(7);

    ht.display();

    return 0;
}
