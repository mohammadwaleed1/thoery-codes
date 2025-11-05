#include <iostream>
using namespace std;

struct Node {
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

// Utility to get height of a node
int getHeight(Node* node) {
        if (node == nullptr) return 0;
        return max(getHeight(node->left), getHeight(node->right)) + 1;
    }

// Utility to get balance factor
int getBalance(Node* node) {
    if (!node) return 0;
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
    if (node=nullptr) return new Node(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
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

// Inorder traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << "(" << root->height << ") ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    int arr[] = {10, 20, 30, 40, 50, 25};
    for (int val : arr)
        root = insert(root, val);

    cout << "Inorder traversal with heights: ";
    inorder(root);
    cout << endl;
}
