//optimal
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* findLoopStart(Node* head) {
    // Edge case: empty list or single node
    if (head == NULL || head->next == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    // If no cycle exists
    if (fast == NULL || fast->next == NULL)
        return NULL;

    // Step 2: Find starting point of loop
    slow = head;

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
