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

Node *rotateList (Node *head, int k) {
    if (head == NULL || k <= 0)
        return head;
    
    Node *curr = head;

    // reaching to the end of k nodes
    while (curr && k > 1) {
        curr = curr->next;
        k--;
    }

    // if k is greater than the length of list
    if (curr == NULL || curr->next == NULL) {
        cout << "Given k is greater than or equal to the length of list!" << endl;
        return head;
    }

    // terminating list at the end of k nodes
    Node *rotatedHead = curr->next;
    curr->next = NULL;

    // reaching to the end of the actual list
    curr = rotatedHead;
    while (curr->next) {
        curr = curr->next;
    }

    // rotating the list
    curr->next = head;

    return rotatedHead;

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
    // head = rotateList (head, 2);
    // head = rotateList (head, 1);
    // head = rotateList (head, 6);
    head = rotateList (head, 7);
    cout << "List after operation: "; printList(head);

    return 0;
}