//optimal
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* random;

    Node(int val) {
        data = val;
        next = NULL;
        random = NULL;
    }
};

Node* cloneLinkedList(Node* head) {
    if (!head) return NULL;

    Node* curr = head;

    // PASS 1: Interleave cloned nodes
    while (curr) {
        Node* copy = new Node(curr->data);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }

    // PASS 2: Set random pointers for clones
    curr = head;
    while (curr) {
        if (curr->random)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }

    // PASS 3: Detach cloned list
    curr = head;
    Node* cloneHead = head->next;

    while (curr) {
        Node* copy = curr->next;
        curr->next = copy->next;
        if (copy->next)
            copy->next = copy->next->next;
        curr = curr->next;
    }

    return cloneHead;
}
