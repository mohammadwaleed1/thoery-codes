#include <iostream>
using namespace std;

class HashTable {
    static const int TABLE_SIZE = 10;
    int table[TABLE_SIZE];
    bool occupied[TABLE_SIZE];
    int numElements;

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = -1;
            occupied[i] = false;
        }
        numElements = 0;
    }

    int hash(int key) {
        return key % TABLE_SIZE;
    }

    // Insert key using your described quadratic probing logic
    void insert(int key) {
        if (numElements == TABLE_SIZE) {
            cout << "Hash table is full! Cannot insert " << key << endl;
            return;
        }

        int index = hash(key); // first hash
        int i = 0;             // probing increment

        // Keep probing until an empty slot is found
        while (occupied[index]) {
            i++; // increase i for next probe
            index = (hash(key) + i * i) % TABLE_SIZE; // quadratic probe
        }

        table[index] = key;
        occupied[index] = true;
        numElements++;
    }

    bool search(int key) {
        int i = 0;
        int index = hash(key);

        while (occupied[index]) {
            if (table[index] == key) return true;
            i++;
            index = (hash(key) + i * i) % TABLE_SIZE;
            if (i == TABLE_SIZE) break; // avoid infinite loop
        }
        return false;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (occupied[i]) cout << i << " --> " << table[i] << endl;
            else cout << i << " --> NULL" << endl;
        }
    }
};

int main() {
    HashTable ht;

    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    ht.insert(25);
    ht.insert(15);

    ht.display();

    cout << "Search 25: " << (ht.search(25) ? "Found" : "Not Found") << endl;
    cout << "Search 40: " << (ht.search(40) ? "Found" : "Not Found") << endl;

    return 0;
}
