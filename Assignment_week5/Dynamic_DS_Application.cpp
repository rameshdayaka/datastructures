#include <iostream> // Library for basic input and output operations
#include <vector> // Library for using the vector container
#include <queue> // Library for using the queue container
#include <stack> // Library for using the stack container
using namespace std; // Standard namespace for simplifying code

// Class definition for the dynamic array
class DynamicArray {
private:
    vector<int> data; // Vector to store elements of the array

public:
    // Method to insert data into the array
    void insertData(int value) {
        data.push_back(value); // Insert data at the end of the vector
    }

    // Method to display the array
    void displayData() {
        cout << "Dynamic Array Elements: "; // Label for the dynamic array
        for (int num : data) { // Loop through each element in the array
            cout << num << " "; // Print the element followed by a space
        }
        cout << endl; // New line after displaying all elements
    }

    // Method to adjust the size of the array
    void adjustSize() {
        int newSize; // Variable to store the new size of the array
        cout << "Enter the new size of the array: "; // Prompt user to enter the new size
        cin >> newSize; // Read user input for the new size
        data.resize(newSize); // Resize the array to the new size
        cout << "Array resized successfully!" << endl; // Message indicating successful resizing
    }
};

// Class definition for the linked list
class LinkedList {
private:
    struct Node {
        int data; // Data stored in the node
        Node* next; // Pointer to the next node

        Node(int val) : data(val), next(nullptr) {} // Constructor to initialize node with data
    };

    Node* head; // Pointer to the head of the linked list

public:
    LinkedList() : head(nullptr) {} // Constructor to initialize head pointer to nullptr

    // Method to insert data into the linked list
    void insertData(int value) {
        Node* newNode = new Node(value); // Create a new node with the given data
        if (!head) { // If the linked list is empty
            head = newNode; // Set the new node as the head
        } else { // If the linked list is not empty
            Node* current = head; // Start traversal from the head
            while (current->next) { // Traverse until the last node
                current = current->next; // Move to the next node
            }
            current->next = newNode; // Insert the new node at the end
        }
    }

    // Method to display the linked list
    void displayData() {
        cout << "Linked List Elements: "; // Label for the linked list
        Node* current = head; // Start traversal from the head
        while (current) { // Traverse until the end of the list
            cout << current->data << " "; // Print the data of the current node
            current = current->next; // Move to the next node
        }
        cout << endl; // New line after displaying all elements
    }
};

// Class definition for the stack
class CustomStack {
private:
    stack<int> customStack; // Stack to store elements

public:
    // Method to push data onto the stack
    void pushData(int value) {
        customStack.push(value); // Push the data onto the stack
    }

    // Method to pop data from the stack
    void popData() {
        if (!customStack.empty()) { // If the stack is not empty
            customStack.pop(); // Pop the top element from the stack
        }
    }

    // Method to display the stack
    void displayData() {
        cout << "Stack Elements: "; // Label for the stack
        stack<int> tempStack = customStack; // Create a temporary copy of the stack
        while (!tempStack.empty()) { // Loop until the temporary stack is empty
            cout << tempStack.top() << " "; // Print the top element of the stack
            tempStack.pop(); // Pop the top element from the temporary stack
        }
        cout << endl; // New line after displaying all elements
    }
};

// Class definition for the queue
class CustomQueue {
private:
    queue<int> customQueue; // Queue to store elements

public:
    // Method to enqueue data into the queue
    void enqueueData(int value) {
        customQueue.push(value); // Enqueue the data into the queue
    }

    // Method to dequeue data from the queue
    void dequeueData() {
        if (!customQueue.empty()) { // If the queue is not empty
            customQueue.pop(); // Dequeue (remove) the front element from the queue
        }
    }

    // Method to display the queue
    void displayData() {
        cout << "Queue Elements: "; // Label for the queue
        queue<int> tempQueue = customQueue; // Create a temporary copy of the queue
        while (!tempQueue.empty()) { // Loop until the temporary queue is empty
            cout << tempQueue.front() << " "; // Print the front element of the queue
            tempQueue.pop(); // Pop the front element from the temporary queue
        }
        cout << endl; // New line after displaying all elements
    }
};

// Class definition for the binary tree
class BinaryTree {
private:
    struct TreeNode {
        int data; // Data stored in the node
        TreeNode* left; // Pointer to the left child node
        TreeNode* right; // Pointer to the right child node

        TreeNode(int val) : data(val), left(nullptr), right(nullptr) {} // Constructor to initialize node with data
    };

    TreeNode* root; // Pointer to the root of the binary tree

    // Private method to insert data into the binary tree
    TreeNode* insertNode(TreeNode* node, int value) {
        if (!node) { // If the current node is nullptr
            return new TreeNode(value); // Create a new node with the given data
        }
        if (value < node->data) { // If the data is less than the current node's data
            node->left = insertNode(node->left, value); // Recursively insert into the left subtree
        } else if (value > node->data) { // If the data is greater than the current node's data
            node->right = insertNode(node->right, value); // Recursively insert into the right subtree
        }
        return node; // Return the modified node
    }

    // Private method to perform inorder traversal of the binary tree
    void inorderTraversal(TreeNode* node) {
        if (node) { // If the current node is not nullptr
            inorderTraversal(node->left); // Traverse the left subtree
            cout << node->data << " "; // Print the data of the current node
            inorderTraversal(node->right); // Traverse the right subtree
        }
    }

public:
    BinaryTree() : root(nullptr) {} // Constructor to initialize root pointer to nullptr

    // Method to insert data into the binary tree
    void insertData(int value) {
        root = insertNode(root, value); // Call the private insert method to insert data into the binary tree
    }

    // Method to display the binary tree
    void displayData() {
        cout << "Binary Tree Elements (Inorder traversal): "; // Label for the binary tree
        inorderTraversal(root); // Call the private inorder traversal method to display the binary tree
        cout << endl; // New line after displaying all elements
    }
};

// Main function to interact with the user and test the data structures
int main() {
    cout << "Welcome to the Dynamic Data Structure Program!" << endl; // Greet the user

    DynamicArray dynamicArray; // Create an instance of the dynamic array
    LinkedList linkedList; // Create an instance of the linked list
    CustomStack customStack; // Create an instance of the stack
    CustomQueue customQueue; // Create an instance of the queue
    BinaryTree binaryTree; // Create an instance of the binary tree

    while (true) { // Enter an infinite loop to keep the application running
        cout << "\nChoose a data structure to work with:" << endl; // Prompt the user to choose a data structure
        cout << "1. Dynamic Array" << endl; // Option to work with dynamic array
        cout << "2. Linked List" << endl; // Option to work with linked list
        cout << "3. Stack" << endl; // Option to work with stack
        cout << "4. Queue" << endl; // Option to work with queue
        cout << "5. Binary Tree" << endl; // Option to work with binary tree
        cout << "6. Exit" << endl; // Option to exit the application

        int choice; // Variable to store user's choice
        cout << "Enter your choice: "; // Prompt the user to enter their choice
        cin >> choice; // Read user's choice

        switch (choice) { // Use a switch statement to perform actions based on user's choice
            case 1: { // If user chooses dynamic array
                int value; // Variable to store data entered by user
                cout << "Enter value to insert into the dynamic array: "; // Prompt user to enter data
                cin >> value; // Read data entered by user
                dynamicArray.insertData(value); // Insert the data into the dynamic array
                cout << "Value inserted into the dynamic array!" << endl; // Message indicating successful insertion
                break; // Exit the switch statement
            }
            case 2: { // If user chooses linked list
                int value; // Variable to store data entered by user
                cout << "Enter value to insert into the linked list: "; // Prompt user to enter data
                cin >> value; // Read data entered by user
                linkedList.insertData(value); // Insert the data into the linked list
                cout << "Value inserted into the linked list!" << endl; // Message indicating successful insertion
                break; // Exit the switch statement
            }
            case 3: { // If user chooses stack
                int value; // Variable to store data entered by user
                cout << "Enter value to push onto the stack: "; // Prompt user to enter data
                cin >> value; // Read data entered by user
                customStack.pushData(value); // Push the data onto the stack
                cout << "Value pushed onto the stack!" << endl; // Message indicating successful push
                break; // Exit the switch statement
            }
            case 4: { // If user chooses queue
                int value; // Variable to store data entered by user
                cout << "Enter value to enqueue into the queue: "; // Prompt user to enter data
                cin >> value; // Read data entered by user
                customQueue.enqueueData(value); // Enqueue the data into the queue
                cout << "Value enqueued into the queue!" << endl; // Message indicating successful enqueue
                break; // Exit the switch statement
            }
            case 5: { // If user chooses binary tree
                int value; // Variable to store data entered by user
                cout << "Enter value to insert into the binary tree: "; // Prompt user to enter data
                cin >> value; // Read data entered by user
                binaryTree.insertData(value); // Insert the data into the binary tree
                cout << "Value inserted into the binary tree!" << endl; // Message indicating successful insertion
                break; // Exit the switch statement
            }
            case 6: { // If user chooses to exit the application
                cout << "Exiting the program." << endl; // Message indicating program exit
                return 0; // Return 0 to indicate successful termination of the program
            }
            default: // If user enters an invalid choice
                cout << "Invalid choice! Please choose again." << endl; // Message indicating invalid choice
        }
    }

    return 0; // Return 0 to indicate successful termination of the program
}
