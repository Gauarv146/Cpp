//optimal
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Insert node at end
void insertEnd(Node*& head, int data) {
    Node* newNode = new Node(data);

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
}

// Print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Get length of linked list
int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Pad list with zeros at front
Node* padWithZeros(Node* head, int count) {
    while (count--) {
        Node* newNode = new Node(0);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// Recursive helper
Node* addHelper(Node* l1, Node* l2, int& carry) {
    if (!l1 && !l2)
        return NULL;

    Node* nextNode = addHelper(l1->next, l2->next, carry);

    int sum = l1->data + l2->data + carry;
    carry = sum / 10;

    Node* curr = new Node(sum % 10);
    curr->next = nextNode;

    return curr;
}

// Optimal approach
Node* addTwoNumbers(Node* l1, Node* l2) {
    int len1 = getLength(l1);
    int len2 = getLength(l2);

    // Make lengths equal
    if (len1 < len2)
        l1 = padWithZeros(l1, len2 - len1);
    else if (len2 < len1)
        l2 = padWithZeros(l2, len1 - len2);

    int carry = 0;
    Node* result = addHelper(l1, l2, carry);

    // Handle final carry
    if (carry) {
        Node* newNode = new Node(carry);
        newNode->next = result;
        result = newNode;
    }

    return result;
}

// Driver code
int main() {
    Node* l1 = NULL;
    Node* l2 = NULL;

    // 342 -> 3->4->2
    insertEnd(l1, 3);
    insertEnd(l1, 4);
    insertEnd(l1, 2);

    // 465 -> 4->6->5
    insertEnd(l2, 4);
    insertEnd(l2, 6);
    insertEnd(l2, 5);

    cout << "First Number:  ";
    printList(l1);

    cout << "Second Number: ";
    printList(l2);

    Node* result = addTwoNumbers(l1, l2);

    cout << "Sum:           ";
    printList(result);

    return 0;
}
