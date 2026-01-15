//optimal
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* addOne(Node* head) {
    if (head == NULL)
        return new Node(1);

    Node* lastNonNine = NULL;
    Node* curr = head;

    while (curr) {
        if (curr->data != 9)
            lastNonNine = curr;
        curr = curr->next;
    }

    if (lastNonNine == NULL) {
        Node* newHead = new Node(1);
        newHead->next = head;
        curr = head;

        while (curr) {
            curr->data = 0;
            curr = curr->next;
        }
        return newHead;
    }

    lastNonNine->data++;

    curr = lastNonNine->next;
    while (curr) {
        curr->data = 0;
        curr = curr->next;
    }

    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(9);
    head->next->next->next = new Node(9);

    cout << "Original number: ";
    printList(head);

    head = addOne(head);

    cout << "After adding 1: ";
    printList(head);

    return 0;
}
