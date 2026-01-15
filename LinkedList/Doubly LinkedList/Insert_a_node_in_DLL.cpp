//optimal
#include <bits/stdc++.h>
using namespace std;

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

void insertAfter(Node* &head, Node* &tail, Node* curr, int X) {

    // Safety check
    if (curr == NULL) return;

    Node* newNode = new Node(X);

    // Step 1: Link new node forward
    newNode->next = curr->next;

    // Step 2: Link new node backward
    newNode->prev = curr;

    // Step 3: Fix next node's prev (if exists)
    if (curr->next != NULL) {
        curr->next->prev = newNode;
    } else {
        // curr was tail
        tail = newNode;
    }

    // Step 4: Fix current node's next
    curr->next = newNode;
}
