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

Node* deleteAllOccurrences(Node* head, int key) {

    Node* curr = head;

    while (curr != NULL) {

        Node* nextNode = curr->next;

        if (curr->data == key) {

            // Link previous node
            if (curr->prev != NULL)
                curr->prev->next = curr->next;
            else
                head = curr->next;   // deleting head

            // Link next node
            if (curr->next != NULL)
                curr->next->prev = curr->prev;

            delete curr;
        }

        curr = nextNode;
    }

    return head;
}
