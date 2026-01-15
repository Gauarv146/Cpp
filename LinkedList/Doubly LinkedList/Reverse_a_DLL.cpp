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

Node* reverseDLL(Node* head) {
    // Edge cases: empty list or single node
    if (head == NULL || head->next == NULL)
        return head;

    Node* curr = head;
    Node* last = NULL;

    while (curr != NULL) {
        // Save current node (will become the new head eventually)
        last = curr;

        // Swap prev and next pointers
        Node* temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        // Move to next node in original order
        // After swap, original next is at curr->prev
        curr = curr->prev;
    }

    // last now points to the original tail → new head
    return last;
}
