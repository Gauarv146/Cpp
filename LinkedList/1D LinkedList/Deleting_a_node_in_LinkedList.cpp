//optimal
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* deleteNode(Node* head, int key) {
    Node** curr = &head;

    while (*curr != NULL) {
        if ((*curr)->data == key) {
            Node* temp = *curr;
            *curr = (*curr)->next;
            delete temp;
            break;
        }
        curr = &((*curr)->next);
    }

    return head;
}

