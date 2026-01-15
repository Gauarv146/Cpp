//optimal
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Utility function to reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Function to check if linked list is palindrome
bool isPalindrome(Node* head) {

    // Edge cases
    if (head == nullptr || head->next == nullptr)
        return true;

    // Step 1: Find middle using slow & fast pointers
    Node* slow = head;
    Node* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half
    Node* secondHalfHead = reverseList(slow->next);

    // Step 3: Compare both halves
    Node* first = head;
    Node* second = secondHalfHead;

    bool isPalin = true;

    while (second != nullptr) {
        if (first->data != second->data) {
            isPalin = false;
            break;
        }
        first = first->next;
        second = second->next;
    }

    // Step 4: Restore the list
    slow->next = reverseList(secondHalfHead);

    return isPalin;
}
