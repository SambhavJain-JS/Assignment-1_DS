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

    int n;
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

    // Displaying the circular linked list
    cout << "Student Names in Circular Linked List:" << endl;
    current = head;
    if (head != NULL) {
        do {
            cout << "---> " << current->name << endl;
            current = current->next;
        } while (current != head);
    }

    // Memory Deallocation
    if (head != NULL) {
        Node *temp;
        do {
            temp = head;
            head = head->next;
            delete temp;
        } while (head != tail->next); // Delete until the last node points to head
    }

    int delete_element;
    cout<<"Enter Number between 1 to "<< n <<": ";
    cin>>delete_element;

    
    return 0;
}
