#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node (int d) {
            data = d;
            next = NULL;
        }
};

Node* newNode(int data) {
    Node* new_node = new Node(data);
    return new_node;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void push(Node** head_ref, int new_data) {
    Node* new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

Node* copyLinkedList(Node *head) {
    Node *result = NULL;
    while (head) {
        push(&result, head->data);
        head = head->next;
    }

    return result;
}

// Must ask clarification questions on how to represent the resultant list
// List1: 7->5->9->4->6->#, represents num1: 75946
// List1: 8->4-#, represents num1: 84
// Result: 7->6->0->3->0->#, , represents num1: 76030
Node* addTwoLists(Node* first, Node* second) {
    if (first == NULL) {
        return copyLinkedList(second);
    }

    if (second == NULL) {
        return copyLinkedList(first);
    }

    Node *result = NULL, *temp = NULL;
    int sum = 0, carry = 0;
    Node dummyResult(-1); Node *tailResult = &dummyResult;

    while (first || second) {
        // common code for addition problems
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        
        // based on how resultant list is to be created we can use
        // dummy node or prepend approach. Its better to use prepend
        // approach since this shall avoid the reversing of the list
        temp = newNode(sum);
        temp->next = result;
        result = temp;

        // move the relevant pointer but always after this check
        if(first)
            first = first->next;
        if(second)
            second = second->next;
    }

    // append carry node if left
    if (carry > 0) {
        temp = newNode(sum);
        temp->next = result;
        result = temp;
    }

    return result;
}

Node* reverse(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;
    // reverse the rest list and put the first element at the end
    Node* rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    // fix the head pointer
    return rest;
}

int main(void) {
    Node* res = NULL;
    Node* first = NULL;
    Node* second = NULL;

    // create first list 7->5->9->4->6
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
    printf("First list: ");
    printList(first);

    // create second list 8->4
    push(&second, 4);
    push(&second, 8);
    cout << "Second list: ";
    printList(second);

    // reverse both the lists O(n) operation. We are exercising the flexibility
    // of modifying the given lists
    first = reverse(first);
    printf("\nFirst list after reverse: ");
    printList(first);

    second = reverse(second);
    printf("Second list after reverse: ");
    printList(second);

    // Add the two lists, O(n) operation. We optimize using approach of
    // adding new nodes to the beginning
    res = addTwoLists(first, second);

    cout << "\nResultant list: ";
    printList(res);
    return 0;
}