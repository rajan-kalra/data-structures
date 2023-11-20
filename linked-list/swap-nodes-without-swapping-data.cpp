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

Node *swapNodes (Node *head, int n1, int n2) {
    if (head == NULL)
        return head;
    
    if (n1 == n2)
        return head;
    
    Node *curr = head, *prev = NULL;

    Node *currX = NULL, *prevX = NULL;
    Node *currY = NULL, *prevY = NULL;

    // we loop until the list nodes are available & either
    // of currX or currY is not found
    while (curr && (currX == NULL || currY == NULL)) {
        if (curr->data == n1) {
            // if n1 is a head node
            if (prev == NULL) {
                prevX = NULL;
                currX = curr;
            // if n1 is not a head node
            } else {
                prevX = prev;
                currX = curr;
            }
        } else if (curr->data == n2) {
            // if n2 is a head node
            if (prev == NULL) {
                prevY = NULL;
                currY = curr;
            // if n2 is not a head node
            } else {
                prevY = prev;
                currY = curr;
            }
        }

        prev = curr;
        curr = curr->next;
    }

    // by end of above loop, we shall have the pointers to both
    // n1 & n2 nodes if they exist

    if (currX == NULL || currY == NULL) {
        cout << "One of the node not found, invalid input!" << endl;
        return head;
    }

    // if n1 was head of the linked list
    if (prevX == NULL) {
        // set n2 as head now
        head = currY;
    } else {
        // set next of prevX as n2
        prevX->next = currY;
    }

    // if n2 was head of the linked list
    if (prevY == NULL) {
        // set n1 as head now
        head = currX;
    } else {
        // set next of prevY as n1
        prevY->next = currX;
    }

    Node *temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;

    return head;
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
    //head = swapNodes(head, 1, 5);
    //head = swapNodes(head, 3, 5);
    //head = swapNodes(head, 4, 5);
    //head = swapNodes(head, 5, 6);
    head = swapNodes(head, 5, 7);
    cout << "List after operation: "; printList(head);

    return 0;
}