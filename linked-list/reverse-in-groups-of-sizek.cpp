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
    if (head == NULL)
        return head;
    
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

Node *reverseInGroupsOfSizeK (Node *head, int k) {
    if ((head == NULL) || (head->next == NULL) || (k == 1))
        return head;

    Node *curr = head;
    int count = k;
    while ((curr) && (count > 1)) {
        curr = curr->next;
        count--;
    }

    if (curr == NULL) {
        Node *newHead = reverseList(head);
        head->next = NULL;
        return newHead;
    }

    Node *nextGroup = curr->next;
    curr->next = NULL;
    Node *newHead = reverseList(head);
    head->next = reverseInGroupsOfSizeK (nextGroup, k);
    return newHead;
}

int main() {
    Node *head = NULL;
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    cout << "List before operation: "; printList(head);
    //head = reverseInGroupsOfSizeK(head, 1);
    //head = reverseInGroupsOfSizeK(head, 2);
    //head = reverseInGroupsOfSizeK(head, 4);
    head = reverseInGroupsOfSizeK(head, 6);
    cout << "List after operation: "; printList(head);
    return 0;
}