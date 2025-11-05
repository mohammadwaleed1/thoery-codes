#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// BST class
class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    // Insert a new value
   void insert(int val) {
    Node* newNode = new Node(val);

    // Case 1: Tree is empty → new node becomes root
    if (root == nullptr) {
        root = newNode;
        return;
    }

    Node* current = root;
    Node* parent = nullptr;

    // Case 2: Tree is not empty → find where to insert
    while (current != nullptr) {
        parent = current;

        if (val < current->data)
            current = current->left;

        else if (val > current->data)
            current = current->right;

        else {
            // Duplicate found → replace existing value
            current->data = val;
            delete newNode; // clean up memory (important!)
            return; // exit early, no need to insert
        }
    }

    // Attach new node in correct position
    if (val < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

    // Inorder traversal (Left → Root → Right)
    void inorder(Node* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Search for a value
    bool search(int val) {
        Node* current = root;
        while (current != nullptr) {
            if (current->data == val)
                return true;
            else if (val < current->data)
                current = current->left;
            else
                current = current->right;
        }
        return false;
    }
};
// Main function
int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder Traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    int val;
    cout << "Enter value to search: ";
    cin >> val;

    if (tree.search(val))
        cout << val << " found in BST." << endl;
    else
        cout << val << " not found in BST." << endl;

    return 0;
}
