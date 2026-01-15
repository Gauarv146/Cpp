//optimal
#include <bits/stdc++.h>
using namespace std;

class DoublyLinkedList {

private:
    struct Node {
        int data;
        Node* prev;
        Node* next;

        Node(int val) {
            data = val;
            prev = NULL;
            next = NULL;
        }
    };

    Node* head;
    Node* tail;
    int sz;

public:
    // Constructor
    DoublyLinkedList() {
        head = tail = NULL;
        sz = 0;
    }

    // Insert at front
    void pushFront(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        sz++;
    }

    // Insert at back
    void pushBack(int val) {
        Node* newNode = new Node(val);

        if (tail == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        sz++;
    }

    // Delete from front
    void popFront() {
        if (head == NULL) return;

        Node* temp = head;

        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }

        delete temp;
        sz--;
    }

    // Delete from back
    void popBack() {
        if (tail == NULL) return;

        Node* temp = tail;

        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }

        delete temp;
        sz--;
    }

    // Print forward
    void printForward() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Print backward
    void printBackward() {
        Node* temp = tail;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    // Get size
    int size() {
        return sz;
    }

    // Destructor
    ~DoublyLinkedList() {
        while (head != NULL) {
            popFront();
        }
    }
};

int main() {

    DoublyLinkedList dll;

    dll.pushBack(10);
    dll.pushBack(20);
    dll.pushFront(5);

    cout << "Forward: ";
    dll.printForward();

    cout << "Backward: ";
    dll.printBackward();

    cout << "Size: " << dll.size() << endl;

    return 0;
}
