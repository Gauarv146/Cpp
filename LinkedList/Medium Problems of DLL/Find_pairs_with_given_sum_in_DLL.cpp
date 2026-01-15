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

void findPairs(Node* head, int target) {
    if (head == NULL) return;

    Node* left = head;
    Node* right = head;

    // Move right pointer to the tail
    while (right->next != NULL) {
        right = right->next;
    }

    // Two-pointer traversal
    while (left != right && right->next != left) {
        int sum = left->data + right->data;

        if (sum == target) {
            cout << "(" << left->data << ", "
                 << right->data << ")" << endl;

            left = left->next;
            right = right->prev;
        }
        else if (sum < target) {
            left = left->next;
        }
        else {
            right = right->prev;
        }
    }
}
