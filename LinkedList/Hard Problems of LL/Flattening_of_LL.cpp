//optimal
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

// Merge two sorted bottom-linked lists
Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* result;

    if (a->data <= b->data) {
        result = a;
        result->bottom = merge(a->bottom, b);
    } else {
        result = b;
        result->bottom = merge(a, b->bottom);
    }

    return result;
}

// Optimal flatten function
Node* flatten(Node* head) {
    // Base case
    if (!head || !head->next)
        return head;

    // Recursively flatten the list to the right
    head->next = flatten(head->next);

    // Merge current list with flattened right list
    head = merge(head, head->next);

    return head;
}
