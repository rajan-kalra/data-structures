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
    head = CreateNode(1);
    head->next = CreateNode(2);
    head->next->next = CreateNode(3);
    head->next->next->next = CreateNode(3);
    head->next->next->next->next = CreateNode(5);
    head->next->next->next->next->next = CreateNode(6);
    cout << "List before operation: "; PrintList(head);
    head = removeDuplicates (head);
    cout << "List after operation: "; PrintList(head);

    Node *head1 = NULL;
    head1 = CreateNode(2);
    head1->next = CreateNode(2);
    head1->next->next = CreateNode(3);
    head1->next->next->next = CreateNode(4);
    head1->next->next->next->next = CreateNode(5);
    head1->next->next->next->next->next = CreateNode(6);
    cout << "List before operation: "; PrintList(head1);
    head1 = removeDuplicates (head1);
    cout << "List after operation: "; PrintList(head1);

    Node *head2 = NULL;
    head2 = CreateNode(1);
    head2->next = CreateNode(2);
    head2->next->next = CreateNode(3);
    head2->next->next->next = CreateNode(4);
    head2->next->next->next->next = CreateNode(5);
    head2->next->next->next->next->next = CreateNode(5);
    cout << "List before operation: "; PrintList(head2);
    head2 = removeDuplicates (head2);
    cout << "List after operation: "; PrintList(head2);

    Node *head3 = NULL;
    head3 = CreateNode(1);
    head3->next = CreateNode(1);
    head3->next->next = CreateNode(1);
    head3->next->next->next = CreateNode(1);
    head3->next->next->next->next = CreateNode(1);
    head3->next->next->next->next->next = CreateNode(1);
    cout << "List before operation: "; PrintList(head3);
    head3 = removeDuplicates (head3);
    cout << "List after operation: "; PrintList(head3);
    return 0;
}