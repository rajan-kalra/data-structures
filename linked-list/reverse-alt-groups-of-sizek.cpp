#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

Node* reverse_nodes(Node* head) {
    if (head == NULL)
        return head;

    Node *curr = head, *next = NULL, *prev = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node *reverse (Node *head, int k, bool toReverse) {
    // case to remember
    if ((head == NULL) || (head->next == NULL) || (k < 1)) {
        return head;
    }

    int count = 1;
    Node *curr = head, *prev = NULL, *old_head = NULL;
    while (curr && (count <= k)) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (toReverse) {
        // ending k size list here
        prev->next = NULL;

        // save the current head as after reverse of
        // k size list, this head will become the last
        // node of k size list
        old_head = head;

        head = reverse_nodes (head);
        
        // calling reverse on rest of the list
        old_head->next = reverse (curr, k, !toReverse);
    } else {
        prev->next = reverse (curr, k, !toReverse);
    }

    return head;
}

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* head3 = NULL;
    Node* result = NULL;

    /* Created Linked list
    is 1->2->3->4->5->6->7->8->9 */
    push(&head1, 9);
    push(&head1, 8);
    push(&head1, 7);
    push(&head1, 6);
    push(&head1, 5);
    push(&head1, 4);
    push(&head1, 3);
    push(&head1, 2);
    push(&head1, 1);
    int k = 1;
    cout << "For k = " << k << endl;
    cout << "Input list: ";
    printList(head1);
    result = reverse(head1, k, true);
    cout << "\nReversed list: ";
    printList(result); cout << "\n\n";

    /* Created Linked list
    is 1->2->3->4->5->6->7->8->9 */
    push(&head2, 9);
    push(&head2, 8);
    push(&head2, 7);
    push(&head2, 6);
    push(&head2, 5);
    push(&head2, 4);
    push(&head2, 3);
    push(&head2, 2);
    push(&head2, 1);
    k = 2;
    cout << "For k = " << k << endl;
    cout << "Input list: ";
    printList(head2);
    result = reverse(head2, k, true);
    cout << "\nReversed list: ";
    printList(result); cout << "\n\n";

    /* Created Linked list
    is 1->2->3->4->5->6->7->8->9 */
    push(&head3, 9);
    push(&head3, 8);
    push(&head3, 7);
    push(&head3, 6);
    push(&head3, 5);
    push(&head3, 4);
    push(&head3, 3);
    push(&head3, 2);
    push(&head3, 1);
    k = 3;
    cout << "For k = " << k << endl;
    cout << "Input list: ";
    printList(head3);
    result = reverse(head3, k, true);
    cout << "\nReversed list: ";
    printList(result);

    return (0);
}
