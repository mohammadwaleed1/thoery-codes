#include <iostream>
using namespace std;

class HashTable {
    static const int TABLE_SIZE = 10;
    int table[TABLE_SIZE];
    bool occupied[TABLE_SIZE]; // track filled slots

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = -1;       // -1 indicates empty
            occupied[i] = false; 
        }
    }

    int hash(int key) {
        return key % TABLE_SIZE;
    }

    // Insert key using linear probing
    void insert(int key) {
        int index = hash(key);
        int start = index;

        while (occupied[index]) {
            index = (index + 1) % TABLE_SIZE;
            if (index == start) {
                cout << "Hash table is full!\n";
                return;
            }
        }
        table[index] = key;
        occupied[index] = true;
    }

    // Search key
    bool search(int key) {
        int index = hash(key);
        int start = index;

        while (occupied[index]) {
            if (table[index] == key) return true;
            index = (index + 1) % TABLE_SIZE;
            if (index == start) break;
        }
        return false;
    }

    // Display table
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (occupied[i]) cout << i << " --> " << table[i] << endl;
            else cout << i << " --> " << "NULL" << endl;
        }
    }
};

int main() {
    HashTable ht;

    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    ht.insert(25); // collision with 30
    ht.insert(15);

    ht.display();

    cout << "Search 25: " << (ht.search(25) ? "Found" : "Not Found") << endl;
    cout << "Search 40: " << (ht.search(40) ? "Found" : "Not Found") << endl;

    return 0;
}
