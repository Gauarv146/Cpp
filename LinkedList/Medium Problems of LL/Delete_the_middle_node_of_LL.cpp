//optimal
#include <iostream>
using namespace std;

// Definition of Node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to delete the middle node
Node* deleteMiddle(Node* head) {
    // Edge case: empty list or single node
    if (head == NULL || head->next == NULL)
        return NULL;

    // Dummy node to simplify deletion
    Node* dummy = new Node(0);
    dummy->next = head;

    Node* slow = dummy;
    Node* fast = head;

    // Move fast by 2 steps and slow by 1 step
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // slow->next is the middle node
    Node* middle = slow->next;
    slow->next = middle->next;
    delete middle;

    // Update head and clean up dummy
    Node* newHead = dummy->next;
    delete dummy;

    return newHead;
}

// Helper function to insert node at end
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node(value);

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

// Helper function to print linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Driver code
int main() {
    Node* head = NULL;

    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    cout << "Original list: ";
    printList(head);

    head = deleteMiddle(head);

    cout << "After deleting middle: ";
    printList(head);

    return 0;
}
