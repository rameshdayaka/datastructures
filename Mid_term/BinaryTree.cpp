#include <iostream>
#include <string>
using namespace std;

// Define a class for the nodes in the binary tree
class TreeNode {
public:
    string data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string d) : data(d), left(nullptr), right(nullptr) {}
};

// Function to insert data into the binary tree
TreeNode* insert(TreeNode* root, string data) {
    // If the root is empty, create a new node and return it
    if (root == nullptr) {
        return new TreeNode(data);
    } else {
        // If the left child is empty, insert data there
        if (root->left == nullptr) {
            root->left = insert(root->left, data);
        // If the left child is occupied, insert data to the right
        } else if (root->right == nullptr) {
            root->right = insert(root->right, data);
        } else {
            // If both left and right children are occupied, go deeper
            root->left = insert(root->left, data);
        }
    }
    return root;
}

// Function to print the binary tree in a hierarchical manner
void print_tree(TreeNode* root, int level = 0) {
    // Print the right subtree with increased indentation
    if (root != nullptr) {
        print_tree(root->right, level + 1);
        // Print the current node's data with proper indentation
        cout << string(4 * level, ' ') << "->" << root->data << endl;
        // Print the left subtree with increased indentation
        print_tree(root->left, level + 1);
    }
}

// Function to create the cashier line represented as a binary tree
TreeNode* create_cashier_line(int size) {
    TreeNode* root = nullptr;  // Initialize the root of the binary tree
    // Iterate over the number of customers in the cashier line
    for (int i = 0; i < size; ++i) {
        // Take input for each customer and insert them into the binary tree
        string data;
        cout << "Enter data for customer " << i + 1 << ": ";
        cin >> data;
        root = insert(root, data);  // Insert the customer into the binary tree
    }
    return root;  // Return the root of the binary tree representing the cashier line
}

// Main part of the program
int main() {
    // Take user input for the number of customers in the cashier line
    int size;
    cout << "Enter the number of customers in the cashier line: ";
    cin >> size;
    // Create the binary tree representing the cashier line
    TreeNode* cashier_line = create_cashier_line(size);
    // Print the binary tree representation of the cashier line
    cout << "\nCashier Line (Binary Tree Representation):" << endl;
    print_tree(cashier_line);  // Call the print_tree function to print the binary tree

    return 0;
}
