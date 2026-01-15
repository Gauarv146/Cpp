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

int lengthOfLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect loop using Floyd's algorithm
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // Loop detected
        if (slow == fast) {

            // Step 2: Count length of the loop
            int length = 1;
            fast = fast->next;

            while (fast != slow) {
                length++;
                fast = fast->next;
            }
            return length;
        }
    }

    // No loop present
    return 0;
}
