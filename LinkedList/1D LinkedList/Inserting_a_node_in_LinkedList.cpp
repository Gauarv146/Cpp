//optimal
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() {
        head = tail = NULL;
        size = 0;
    }

    void insert(int val, int pos) {
        if (pos < 1 || pos > size + 1) return;

        if (pos == 1) {
            insertAtHead(val);
        } else if (pos == size + 1) {
            insertAtTail(val);
        } else {
            insertInMiddle(val, pos);
        }
    }

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;

        if (size == 0) {
            tail = newNode;
        }
        size++;
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);

        if (size == 0) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void insertInMiddle(int val, int pos) {
        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }

    void print() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList ll;

    ll.insert(10, 1);
    ll.insert(20, 2);
    ll.insert(30, 3);
    ll.insert(25, 3);

    ll.print();
    return 0;
}
