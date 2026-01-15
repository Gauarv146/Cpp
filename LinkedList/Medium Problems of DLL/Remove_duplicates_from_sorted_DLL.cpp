//optimal
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        prev = next = NULL;
    }
};

Node* removeDuplicates(Node* head) {
    if (head == NULL) return head;

    Node* curr = head;

    while (curr != NULL && curr->next != NULL) {
        if (curr->data == curr->next->data) {
            Node* dup = curr->next;

            curr->next = dup->next;
            if (dup->next != NULL) {
                dup->next->prev = curr;
            }

            delete dup;
        } else {
            curr = curr->next;
        }
    }

    return head;
}
