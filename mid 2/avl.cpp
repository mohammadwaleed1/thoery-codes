#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height; // store height of this node

    Node(int val) {
        data = val;
        left = right = nullptr;
        height = 1; // leaf node has height 1
    }
};

class AVL {
public:
    Node* root;

    AVL() {
        root = nullptr;
    }

    // Utility to get height of a node
    int getHeight(Node* node) {
        if (node == nullptr) return 0;
        return max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    // Utility to get balance factor
    int getBalance(Node* node) {
        if (node=nullptr) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // Right rotation
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x; // new root
    }

    // Left rotation
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y; // new root
    }

    // Insert a node in AVL tree
    Node* insert(Node* node, int key) {
        // Normal BST insert
        if (node == nullptr) return new Node(key);
        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        else node->data=key;
            return node; // no duplicates

        // Update height
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // Check balance
        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && key < node->left->data)
            return rightRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && key > node->right->data)
            return leftRotate(node);

        // Right Left Case
        if (balance < -1 && key < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node; // unchanged
    }
    Node* findMax(Node* node) {
        while (node != nullptr && node->right != nullptr)
            node = node->right;
        return node;
    }
    Node* deleteRec(Node* node, int key) {
        if (node == nullptr) return nullptr;

        if (key < node->data) {
            node->left = deleteRec(node->left, key);
        } else if (key > node->data) {
            node->right = deleteRec(node->right, key);
        } else {
            // Node found
            if (node->left == nullptr && node->right == nullptr) { // Leaf
                delete node;
                return nullptr;
            } else if (node->left == nullptr) { // Only right child
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) { // Only left child
                Node* temp = node->left;
                delete node;
                return temp;
            } else { // Two children
                Node* maxNode = findMax(node->left); // Max in left subtree
                node->data = maxNode->data;          // Replace value
                node->left = deleteRec(node->left, maxNode->data); // Delete duplicate
            }
        }
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // Check balance
        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && key < node->left->data)
            return rightRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && key > node->right->data)
            return leftRotate(node);

        // Right Left Case
        if (balance < -1 && key < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    // Inorder traversal
    void inorder(Node* root) {
        if (root) {
            inorder(root->left);
            cout << root->data << "(" << root->height << ") ";
            inorder(root->right);
        }
    }
    void insertrec(int key){
        root=insert(root,key);
    }
    
};

int main() {
    AVL tree;

    int arr[] = {200,50,300,400,700,150};
    for (int i = 0; i < 6; i++) {
        tree.root = tree.insert(tree.root, arr[i]);
    }

    cout << "Inorder traversal with heights: ";
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}
