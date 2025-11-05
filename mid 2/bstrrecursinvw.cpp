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

    // Recursive insert helper
    Node* insertRec(Node* node, int val) {
        if (node == nullptr)
            return new Node(val); // create new node when reaching empty spot

        if (val < node->data)
            node->left = insertRec(node->left, val);
        else if (val > node->data)
            node->right = insertRec(node->right, val);
        else node->data=val;
        return node; // return unchanged node pointer
    }

    // Public insert function
    void insert(int val) {
        root = insertRec(root, val);
    }

    // Recursive inorder traversal
    void inorder(Node* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Recursive search helper
    bool searchRec(Node* node, int val) {
        if (node == nullptr)
            return false;
        if (node->data == val)
            return true;
        else if (val < node->data)
            return searchRec(node->left, val);
        else
            return searchRec(node->right, val);
    }

    // Public search function
    bool search(int val) {
        return searchRec(root, val);
    }
     Node* removeRec(Node* node, int key, bool &found) {
        if (node == nullptr)
            return nullptr;

        if (key < node->data)
            node->left = removeRec(node->left, key, found);
        else if (key > node->data)
            node->right = removeRec(node->right, key, found);
        else {
            found = true; // node found

            // Case 1: Leaf node
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            // Case 2: Only right child
            else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            // Case 3: Only left child
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Case 4: Two children
            else {
                Node* maxNode = findMax(node->left);
                node->data = maxNode->data;
                node->left = removeRec(node->left, maxNode->data, found);
            }
        }

        return node;
    }

    // Find maximum node in a subtree
    Node* findMax(Node* node) {
        while (node->right != nullptr)
            node = node->right;
        return node;
    }
    bool remove(int key) {
        bool found = false;
        root = removeRec(root, key, found);
        return found;
    }
};


// Main function
int main() {
    BST tree;

    // Insert elements
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
