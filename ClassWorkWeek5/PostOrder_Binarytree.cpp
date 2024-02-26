#include <iostream>

using namespace std;

// Define a structure representing a node in a binary tree
struct Node {
    int data;     // Value stored in the node
    Node* left;   // Pointer to the left child node
    Node* right;  // Pointer to the right child node
};

// Function to create a new node with the given data
Node* createNode(int data) {
    // Allocate memory for a new node
    Node* newNode = new Node();
    // Set the value of the new node
    newNode->data = data;
    // Initialize left and right child pointers to null
    newNode->left = newNode->right = nullptr;
    // Return the newly created node
    return newNode;
}

// Function to print nodes in a binary tree using preorder traversal
void printPreorder(Node* root) {
    // Base case: if the current node is null, return
    if (root == nullptr)
        return;
    // Print the value of the current node
    cout << root->data << " ";
    // Recursively traverse the left subtree
    printPreorder(root->left);
    // Recursively traverse the right subtree
    printPreorder(root->right);
}

int main() {
    // Create the root node with value 1
    Node* root = createNode(1);
    // Create left and right child nodes of the root
    root->left = createNode(2);
    root->right = createNode(3);
    // Create a left child node of the left child of the root
    root->left->left = createNode(4);

    // Print the preorder traversal of the tree
    cout << "Preorder traversal of the tree: ";
    printPreorder(root);
    cout << endl;

    // Free the memory allocated for nodes to avoid memory leaks
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
