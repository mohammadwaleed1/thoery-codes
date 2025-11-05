#include <iostream>
#include <queue>
using namespace std;

// ===============================
// Node Class
// ===============================
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

// ===============================
// BST Class
// ===============================
class BST {
private:
    Node* root;

    // Insert recursively
    Node* insertRec(Node* node, int key) {
        if (node == nullptr) return new Node(key);
        if (key < node->data) node->left = insertRec(node->left, key);
        else if (key > node->data) node->right = insertRec(node->right, key);
        return node; // ignore duplicates
    }

    // Search recursively
    bool searchRec(Node* node, int key) {
        if (node == nullptr) return false;
        if (node->data == key) return true;
        else if (key < node->data) return searchRec(node->left, key);
        else return searchRec(node->right, key);
    }

    // Find maximum in a subtree
    Node* findMax(Node* node) {
        while (node != nullptr && node->right != nullptr)
            node = node->right;
        return node;
    }

    // Delete recursively using left subtree max
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
        return node;
    }

    // Traversals
    void inorderRec(Node* node) {
        if (node == nullptr) return;
        inorderRec(node->left);
        cout << node->data << " ";
        inorderRec(node->right);
    }

    void preorderRec(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorderRec(node->left);
        preorderRec(node->right);
    }

    void postorderRec(Node* node) {
        if (node == nullptr) return;
        postorderRec(node->left);
        postorderRec(node->right);
        cout << node->data << " ";
    }

    // Height of tree
    int heightRec(Node* node) {
        if (node == nullptr) return 0;
        return max(heightRec(node->left), heightRec(node->right)) + 1;
    }

    // Count nodes
    int countNodesRec(Node* node) {
        if (node == nullptr) return 0;
        return 1 + countNodesRec(node->left) + countNodesRec(node->right);
    }

    // Check full binary tree
    bool isFullRec(Node* node) {
        if (node == nullptr) return true;
        if (node->left == nullptr && node->right == nullptr) return true;
        if (node->left != nullptr && node->right != nullptr)
            return isFullRec(node->left) && isFullRec(node->right);
        return false;
    }

    // Check complete binary tree
    bool isCompleteRec(Node* node) {
        if (node == nullptr) return true;
        queue<Node*> q;
        q.push(node);
        bool nullFound = false;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr == nullptr) {
                nullFound = true;
            } else {
                if (nullFound) return false;
                if (curr->left != nullptr || curr->left == nullptr) q.push(curr->left);
                if (curr->right != nullptr || curr->right == nullptr) q.push(curr->right);
            }
        }
        return true;
    }

public:
    BST() { root = nullptr; }

    void insert(int key) { root = insertRec(root, key); }
    void remove(int key) { root = deleteRec(root, key); }
    bool search(int key) { return searchRec(root, key); }

    void inorder() { 
        inorderRec(root); 
        cout << endl; }
    void preorder() { 
        preorderRec(root); 
        cout << endl; }
    void postorder() { 
        postorderRec(root); 
        cout << endl; }

    void levelOrder() {
        if (root == nullptr) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }
        cout << endl;
    }

    int height() { return heightRec(root); }
    int countNodes() { return countNodesRec(root); }
    bool isFullBinaryTree() { return isFullRec(root); }
    bool isCompleteBinaryTree() { return isCompleteRec(root); }
};

// ===============================
// MAIN FUNCTION
// ===============================
int main() {
    BST tree;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int val : values) tree.insert(val);

    cout << "Inorder Traversal: ";
    tree.inorder();

    cout << "Preorder Traversal: ";
    tree.preorder();

    cout << "Postorder Traversal: ";
    tree.postorder();

    cout << "Level Order Traversal: ";
    tree.levelOrder();

    int key = 60;
    cout << "Search " << key << ": " << (tree.search(key) ? "Found" : "Not Found") << endl;

    tree.remove(50);
    cout << "After deleting 50 (Inorder): ";
    tree.inorder();

    cout << "Height of Tree: " << tree.height() << endl;
    cout << "Total Nodes: " << tree.countNodes() << endl;
    cout << "Is Full Binary Tree? " << (tree.isFullBinaryTree() ? "Yes" : "No") << endl;
    cout << "Is Complete Binary Tree? " << (tree.isCompleteBinaryTree() ? "Yes" : "No") << endl;

    return 0;
}
