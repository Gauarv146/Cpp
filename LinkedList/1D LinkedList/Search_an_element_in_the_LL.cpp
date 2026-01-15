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

// Preprocess linked list into a hash set
unordered_set<int> buildHash(Node* head) {
    unordered_set<int> st;
    while (head != NULL) {
        st.insert(head->data);
        head = head->next;
    }
    return st;
}

// Optimal search: O(1) average
bool searchElement(const unordered_set<int>& st, int key) {
    return st.find(key) != st.end();
}
