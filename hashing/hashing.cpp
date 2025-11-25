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

    // First hash function
    int hash1(int key) {
        return key % TABLE_SIZE;
    }

    // Second hash function (for double hashing)
    int hash2(int key) {
        int R = 7; // a prime smaller than TABLE_SIZE
        return R - (key % R);
    }

    // Insert using double hashing
    void insert(int key) {
        if (numElements == TABLE_SIZE) {
            cout << "Hash table is full! Cannot insert " << key << endl;
            return;
        }

        int index1 = hash1(key);
        int index2 = hash2(key);
        int i = 0;
        int index = index1;

        while (occupied[index]) {
            i++;
            index = (index1 + i * index2) % TABLE_SIZE;
        }

        table[index] = key;
        occupied[index] = true;
        numElements++;
    }

    // Search using double hashing
    bool search(int key) {
        int index1 = hash1(key);
        int index2 = hash2(key);
        int i = 0;
        int index = index1;

        while (occupied[index]) {
            if (table[index] == key) return true;
            i++;
            if (i == TABLE_SIZE) break; // avoid infinite loop
            index = (index1 + i * index2) % TABLE_SIZE;
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
