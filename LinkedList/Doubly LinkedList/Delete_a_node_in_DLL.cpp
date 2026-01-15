//optimal
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

void deleteNode(Node* node) {
    // Safety check
    if (node == NULL) return;

    // If previous node exists, link it to next
    if (node->prev != NULL) {
        node->prev->next = node->next;
    }

    // If next node exists, link it to previous
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }

    delete node;
}
