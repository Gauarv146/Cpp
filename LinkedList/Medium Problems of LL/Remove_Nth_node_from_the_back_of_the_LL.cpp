//optimal
#include <iostream>
using namespace std;

// Definition of the Node
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the end
Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Optimal function to remove Nth node from end
Node* removeNthFromEnd(Node* head, int n) {
    Node dummy;
    dummy.next = head;

    Node* fast = &dummy;
    Node* slow = &dummy;

    // Move fast pointer n steps ahead
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    // Move both pointers until fast reaches the last node
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Delete the target node
    Node* delNode = slow->next;
    slow->next = delNode->next;
    delete delNode;

    return dummy.next;
}

// Driver code
int main() {
    Node* head = NULL;
    int n, size, value;

    cout << "Enter number of nodes: ";
    cin >> size;

    cout << "Enter node values: ";
    for (int i = 0; i < size; i++) {
        cin >> value;
        head = insertAtEnd(head, value);
    }

    cout << "Enter N (from end): ";
    cin >> n;

    cout << "Original List: ";
    printList(head);

    head = removeNthFromEnd(head, n);

    cout << "Modified List: ";
    printList(head);

    return 0;
}
