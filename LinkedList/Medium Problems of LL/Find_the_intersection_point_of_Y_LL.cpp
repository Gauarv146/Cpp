//optimal
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int getLength(Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

Node* getIntersectionNode(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    Node* ptr1 = head1;
    Node* ptr2 = head2;

    if (len1 > len2) {
        int diff = len1 - len2;
        while (diff--) {
            ptr1 = ptr1->next;
        }
    } else {
        int diff = len2 - len1;
        while (diff--) {
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2) {
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {
    Node* common = new Node{30, NULL};
    common->next = new Node{40, NULL};

    Node* head1 = new Node{10, NULL};
    head1->next = new Node{20, common};

    Node* head2 = new Node{15, common};

    Node* intersect = getIntersectionNode(head1, head2);

    if (intersect != NULL)
        cout << "Intersection at node with data: " << intersect->data;
    else
        cout << "No intersection";

    return 0;
}
