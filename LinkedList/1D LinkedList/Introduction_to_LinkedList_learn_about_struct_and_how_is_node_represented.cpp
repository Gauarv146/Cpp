//optimal
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head;
    Node* tail;
};

void insertAtTail(LinkedList& list, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (list.head == NULL) {
        list.head = newNode;
        list.tail = newNode;
    } else {
        list.tail->next = newNode;
        list.tail = newNode;
    }
}

void traverse(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    LinkedList list;
    list.head = NULL;
    list.tail = NULL;

    insertAtTail(list, 10);
    insertAtTail(list, 20);
    insertAtTail(list, 30);

    traverse(list.head);
}
