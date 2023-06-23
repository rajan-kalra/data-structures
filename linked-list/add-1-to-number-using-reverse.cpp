#include <iostream>
#include <stdio.h>
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
 
Node* CreateNode (int data) {
    Node *node = new Node(data);
    return node;
}
 
void PrintList (Node *head) {
    if (head == NULL)
        return;

    while (head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "#" << endl;
}

Node *reverseList (Node *head) {
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node *Add1ToReveresedList (Node *head) {
    Node *curr = head;
    int carry = 1;
    int sum;
    Node *temp;

    while (curr) {
        sum = curr->data + carry;
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;

        curr->data = sum;

        // we need this temp only for the case
        // if we need to add new node at the
        // end of the list in case of carry in
        // the end
        temp = curr;
        curr = curr->next;
    }

    if (carry > 0) {
        temp->next = CreateNode(carry);
    }

    return head;
}

Node *add1ToListUsingReverse (Node *head) {
    head = reverseList (head);
    head = Add1ToReveresedList (head);
    head = reverseList (head);

    return head;
}

int main() {
    Node *head = NULL;
    head = CreateNode(9);
    head->next = CreateNode(9);
    head->next->next = CreateNode(9);
    head->next->next->next = CreateNode(9);
    cout << "List before operation: "; PrintList(head);
    head = add1ToListUsingReverse (head);
    cout << "List after operation: "; PrintList(head);
    return 0;
}