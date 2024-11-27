#include <iostream>
#include <string>
using namespace std;

// Node structure to store a student's name
struct Node {
    string name;
    Node *next;
};

int main() {
    cout << "Circular Linked List Program Started" << endl;

    int n, delete_element;
    string studentName;

    Node *head = NULL, *tail = NULL, *current;

    cout << "Enter the number of students: ";
    cin >> n;

    // Input student names and create the circular linked list
    for (int i = 1; i <= n; i++) {
        cout << "Enter the name of student " << i << ": ";
        cin >> studentName;

        current = new Node;
        current->name = studentName;
        current->next = NULL;

        if (head == NULL) {
            head = current;
            tail = current;
            tail->next = head; // Making it circular
        } else {
            tail->next = current;
            tail = current;
            tail->next = head; // Making it circular
        }
    }

    cout << "Enter the value of delete_element (1 to " << n << "): ";
    cin >> delete_element;

    // Process to remove every delete_element-th node
    current = head;
    Node *prev = tail; // Keep track of the previous node

    while (n > 1) { // Continue until one node is left
        for (int count = 1; count < delete_element; count++) {
            prev = current;
            current = current->next;
        }

        // Remove the current node
        cout << "Removing: " << current->name << endl;
        prev->next = current->next;

        // If deleting head node, update head
        if (current == head) {
            head = current->next;
        }

        delete current;
        current = prev->next; // Move to the next node
        n--;
    }

    // Display the last remaining node
    cout << "Last remaining student: " << head->name << endl;

    // Cleanup
    delete head;
    return 0;
}
