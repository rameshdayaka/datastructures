#include <iostream>
#include <string>
using namespace std;

// Define a class for the nodes in the linked list
class Node {
public:
    string data;
    Node* next;

    Node(string d) : data(d), next(nullptr) {}
};

// Define a class for the linked list
class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void append(string data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = new_node;
            return;
        }
        Node* last_node = head;
        while (last_node->next) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }

    void print_list() {
        Node* current_node = head;
        while (current_node) {
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
        cout << endl;
    }
};

LinkedList create_linked_list(int size) {
    LinkedList linked_list;
    for (int i = 0; i < size; ++i) {
        string data;
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;
        linked_list.append(data);
    }
    return linked_list;
}

int main() {
    int size;
    cout << "Enter the size of the linked list: ";
    cin >> size;
    LinkedList linked_list = create_linked_list(size);
    cout << "Linked List:" << endl;
    linked_list.print_list();

    return 0;
}
