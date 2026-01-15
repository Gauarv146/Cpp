//optimal
#include <bits/stdc++.h>
using namespace std;

/* Definition of singly linked list node */
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to segregate even and odd nodes */
Node* segregateEvenOdd(Node* head) {
    if (!head || !head->next)
        return head;

    Node *evenHead = NULL, *evenTail = NULL;
    Node *oddHead  = NULL, *oddTail  = NULL;

    Node* curr = head;

    while (curr) {
        Node* nextNode = curr->next;   // store next node
        curr->next = NULL;             // detach current node

        if (curr->data % 2 == 0) {
            if (!evenHead) {
                evenHead = evenTail = curr;
            } else {
                evenTail->next = curr;
                evenTail = curr;
            }
        } else {
            if (!oddHead) {
                oddHead = oddTail = curr;
            } else {
                oddTail->next = curr;
                oddTail = curr;
            }
        }

        curr = nextNode;
    }

    // If there are no even nodes
    if (!evenHead)
        return oddHead;

    // Join even list with odd list
    evenTail->next = oddHead;
    return evenHead;
}

/* Utility function to insert node at end */
Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head)
        return newNode;

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

/* Utility function to print linked list */
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

/* Driver code */
int main() {
    Node* head = NULL;

    // Example input: 1 → 2 → 3 → 4 → 5 → 6
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 6);

    cout << "Original List: ";
    printList(head);

    head = segregateEvenOdd(head);

    cout << "After Segregation: ";
    printList(head);

    return 0;
}
