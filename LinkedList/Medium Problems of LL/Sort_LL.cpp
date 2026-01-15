//optimal
#include <iostream>
using namespace std;

/* Definition of Node */
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

/* Insert node at end of linked list */
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

/* Print linked list */
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/* Merge two sorted linked lists */
Node* merge(Node* left, Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    Node* result;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

/* Find middle of linked list */
Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/* Merge Sort on Linked List */
Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* mid = findMiddle(head);
    Node* rightHead = mid->next;
    mid->next = NULL;

    Node* left = mergeSort(head);
    Node* right = mergeSort(rightHead);

    return merge(left, right);
}

/* Driver code */
int main() {
    Node* head = NULL;

    insertAtEnd(head, 5);
    insertAtEnd(head, 3);
    insertAtEnd(head, 8);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);

    cout << "Original Linked List: ";
    printList(head);

    head = mergeSort(head);

    cout << "Sorted Linked List:   ";
    printList(head);

    return 0;
}
