#include <iostream>
using namespace std;
 
class Node {
    public:
        int data;
        Node *next;
        Node (int data) {
            this->data = data;
            next = NULL;
        }
};
 
Node* createNode (int data) {
    Node *node = new Node(data);
    return node;
}

void printList (Node *head) {
    if (head == NULL)
        return;

    while (head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "#" << endl;
}

Node* reverseList (Node *head) {
    Node *curr = head;
    Node *prev = NULL;
    Node *next;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

bool compareLists (Node *head1, Node *head2) {
    while (head1 && head2 && head1->data == head2->data) {
        head1 = head1->next;
        head2 = head2->next;
    }

    if (head1 == NULL && head2 == NULL)
        return true;
    else
        return false;
}

bool isListPalindrome (Node *head) {
    if (head == NULL || head->next == NULL)
        return false;

    Node *fast = head;
    Node *slow = head;
    Node *prevSlow = NULL;
    Node *mid = NULL;
    Node *secondHalf;

    while (fast && fast->next) {
        prevSlow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // if fast is NULL, its a even length list
    if (fast == NULL) {
        prevSlow->next = NULL;
        secondHalf = slow;
    // if fast->next is NULL, its an odd length list
    } else {
        secondHalf = slow->next;
        prevSlow->next = NULL;
        // keeping middle node as standalone
        mid = slow;
    }

    Node *newSecondHalfHead = reverseList (secondHalf);
    bool result = compareLists (head, newSecondHalfHead);
    secondHalf = reverseList (newSecondHalfHead);

    /* reconnect the list */
    // mid if not null, it was an odd length list
    if (mid) {
        prevSlow->next = mid;
        mid->next = secondHalf;
    // if  mid is NULL, it was an even length list
    } else {
        prevSlow->next = secondHalf;
    }

    return result;
}
 
int main() {
    Node *head = NULL;
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(2);
    head->next->next->next->next->next = createNode(1);
    cout << "List before operations: "; printList(head);

    isListPalindrome(head) ? cout << "Given list represents a palindrome!" << endl : cout << "Given list doesn't represent a palindrome!" << endl;

    cout << "List after operations: "; printList(head);

    return 0;
}