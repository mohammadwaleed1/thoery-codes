#include <iostream>
using namespace std;

class HashTable {
    static const int TABLE_SIZE = 10;
    int table[TABLE_SIZE];
    bool occupied[TABLE_SIZE];

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = -1;
            occupied[i] = false;
        }
    }

    int hash(int key) {
        return key % TABLE_SIZE;
    }

    // Insert using linear probing
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
            if (table[index] == key)
                return true;

            index = (index + 1) % TABLE_SIZE;

            if (index == start)
                break;
        }
        return false;
    }

    // Delete key using rehashing (without vector)
    void deleteKey(int key) {
        if (!search(key)) {
            cout << "Key not found!\n";
            return;
        }

        // Step 1: store remaining keys in a temporary array
        int temp[TABLE_SIZE];
        int count = 0;

        for (int i = 0; i < TABLE_SIZE; i++) {
            if (occupied[i] && table[i] != key) {
                temp[count++] = table[i];
            }
        }

        // Step 2: clear the table
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = -1;
            occupied[i] = false;
        }

        // Step 3: reinsert remaining keys
        for (int i = 0; i < count; i++) {
            insert(temp[i]);
        }

        cout << "Key " << key << " deleted and table rehashed.\n";
    }

    // Display table
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (occupied[i])
                cout << i << " --> " << table[i] << endl;
            else
                cout << i << " --> NULL" << endl;
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

    cout << "Before deletion:\n";
    ht.display();

    ht.deleteKey(25);

    cout << "\nAfter deletion and rehashing:\n";
    ht.display();

    return 0;
}
