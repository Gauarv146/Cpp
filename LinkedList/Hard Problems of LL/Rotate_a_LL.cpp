//optimal
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* rotateRight(Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    Node* curr = head;
    int length = 1;

    // Step 1: Find length and tail in one traversal
    while (curr->next != NULL) {
        curr = curr->next;
        length++;
    }

    // Step 2: Make it circular
    curr->next = head;

    // Step 3: Normalize k
    k = k % length;
    int stepsToNewTail = length - k;

    // Step 4: Find new tail
    Node* newTail = curr;
    while (stepsToNewTail--) {
        newTail = newTail->next;
    }

    // Step 5: Break the circle
    Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}
