//optimal
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* sort012(Node* head) {
    if (!head || !head->next)
        return head;

    Node *zeroH = NULL, *zeroT = NULL;
    Node *oneH  = NULL, *oneT  = NULL;
    Node *twoH  = NULL, *twoT  = NULL;

    Node* curr = head;

    while (curr) {
        Node* nextNode = curr->next;
        curr->next = NULL;

        if (curr->data == 0) {
            (zeroH ? zeroT->next : zeroH) = curr;
            zeroT = curr;
        }
        else if (curr->data == 1) {
            (oneH ? oneT->next : oneH) = curr;
            oneT = curr;
        }
        else {
            (twoH ? twoT->next : twoH) = curr;
            twoT = curr;
        }

        curr = nextNode;
    }

    if (zeroT) zeroT->next = oneH ? oneH : twoH;
    if (oneT)  oneT->next  = twoH;

    return zeroH ? zeroH : (oneH ? oneH : twoH);
}
