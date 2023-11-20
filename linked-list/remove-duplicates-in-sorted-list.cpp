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

Node *removeDuplicates (Node *head) {
    if (head == NULL || head->next == NULL)
        return head;
    
    Node *curr = head;

    while (curr && curr->next) {
        if (curr->data == curr->next->data) {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }

    return head;
}

int main() {
    Node *head = NULL;
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    cout << "List before operation: "; printList(head);
    head = removeDuplicates (head);
    cout << "List after operation: "; printList(head);

    Node *head1 = NULL;
    head1 = createNode(2);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);
    head1->next->next->next->next = createNode(5);
    head1->next->next->next->next->next = createNode(6);
    cout << "List before operation: "; printList(head1);
    head1 = removeDuplicates (head1);
    cout << "List after operation: "; printList(head1);

    Node *head2 = NULL;
    head2 = createNode(1);
    head2->next = createNode(2);
    head2->next->next = createNode(3);
    head2->next->next->next = createNode(4);
    head2->next->next->next->next = createNode(5);
    head2->next->next->next->next->next = createNode(5);
    cout << "List before operation: "; printList(head2);
    head2 = removeDuplicates (head2);
    cout << "List after operation: "; printList(head2);

    Node *head3 = NULL;
    head3 = createNode(1);
    head3->next = createNode(1);
    head3->next->next = createNode(1);
    head3->next->next->next = createNode(1);
    head3->next->next->next->next = createNode(1);
    head3->next->next->next->next->next = createNode(1);
    cout << "List before operation: "; printList(head3);
    head3 = removeDuplicates (head3);
    cout << "List after operation: "; printList(head3);
    return 0;
}