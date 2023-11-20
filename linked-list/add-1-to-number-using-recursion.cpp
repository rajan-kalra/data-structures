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

int addWithCarry(Node *head) {
    if (head == NULL)
        return 1;
    
    int sum = head->data + addWithCarry(head->next);

    int carry = sum >= 10 ? 1 : 0;
    head->data = sum % 10;
    return carry;
}

Node *add1ToListUsingRecursion (Node *head) {
    int carry = addWithCarry(head);
    
    if (carry > 0) {
        Node *node = createNode(carry);
        node->next = head;
        head = node;
    }

    return head;
}

int main() {
    Node *head = NULL;
    head = createNode(1);
    head->next = createNode(9);
    head->next->next = createNode(9);
    head->next->next->next = createNode(9);
    cout << "List before operation: "; printList(head);
    head = add1ToListUsingRecursion (head);
    cout << "List after operation: "; printList(head);
    return 0;
}