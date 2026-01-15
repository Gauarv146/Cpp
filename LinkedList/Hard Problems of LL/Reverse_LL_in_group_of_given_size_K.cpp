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

Node* reverseKGroup(Node* head, int k) {
    Node* curr = head;
    int count = 0;

    // Step 1: Check if k nodes exist
    while (curr != NULL && count < k) {
        curr = curr->next;
        count++;
    }

    // If less than k nodes, do not reverse
    if (count < k) return head;

    // Step 2: Reverse first k nodes
    curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    count = 0;

    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Step 3: Recursive call for remaining list
    head->next = reverseKGroup(curr, k);

    // Step 4: prev is new head of this segment
    return prev;
}
