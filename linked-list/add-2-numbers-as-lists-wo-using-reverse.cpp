#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node (int k) {
            data = k;
            next = NULL;
        }
};

Node *CreateNode (int k) {
    Node *node = new Node (k);
    return node;
}

// It adds new node in the beginning of the linked list
Node* AddNode (Node *head, int k) {
    if (head == NULL) {
        head = CreateNode (k);
        return head;
    }

    Node *next = head;
    head = CreateNode (k);
    head->next = next;
    return head;
}

void PrintList (Node *head) {
    if (head == NULL) {
        cout << "Empty list";
        return;
    }

    while (head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

Node *AddSameSizeList (Node *head1, Node *head2, int& carry) {
    // Base case to stop recursion we can check for
    // head1 or head2 as both are same size
    if (head1 == NULL) {
        return NULL;
    }

    // if looked closely, we are creating an empty node
    // in each recursive call & this node remains in
    // recursion stack until recursion unrolls
    Node *result = CreateNode (0);
    result->next = AddSameSizeList (head1->next, head2->next, carry);

    // common code for add list problems
    int sum = head1->data + head2->data + carry;
    carry = sum >= 10 ? 1 : 0;
    sum = sum % 10;

    // put sum into the result node
    result->data = sum;

    return result;
}

// utility function
int GetSize (Node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }

    return count;
}

// utility function
Node *MoveLongList (Node* head, int diff) {
    while (diff != 0) {
        head = head->next;
        diff--;
    }

    return head;
}

// utility function
// very important & critical step, must go through this all times
Node *AddLeftOverList (Node *longListHead, Node *longListDiff, Node *result, int& carry) {
    // keep recursing the long list head until we reach the pointer pointing to the diff node
    if (longListHead != longListDiff) {
        result = AddLeftOverList (longListHead->next, longListDiff, result, carry);
        
        // common code for add list problems
        int sum = longListHead->data + carry;
        carry = sum >= 10 ? 1 : 0;
        sum = sum % 10;

        result = AddNode (result, sum);
    }

    return result;
}

Node *AddLists (Node *head1, Node *head2) {
    if (head1 == NULL) {
        // should create a new list with values equal to head2
        return head2;
    }
        
    if (head2 == NULL) {
        // should create a new list with values equal to head1
        return head1;
    }

    int carry = 0;
    int size1 = GetSize (head1);
    int size2 = GetSize (head2);

    Node* result;
    Node* current;

    // both lists are same size
    if (size1 == size2) {
        result = AddSameSizeList (head1, head2, carry);
    // both lists are different size
    } else {
        // find the size diff of 2 lists, say k
        int diff = abs(size1 - size2);

        if (size1 < size2) {
            // move k nodes in the longer list
            current = MoveLongList (head2, diff);

            // add same size lists now
            result = AddSameSizeList (head1, current, carry);

            // append the remaining nodes of longer size list
            // to the result of same size lists
            result = AddLeftOverList (head2, current, result, carry);
        } else {
            // move k nodes in the longer list
            current = MoveLongList (head1, diff);

            // add same size lists now
            result = AddSameSizeList (current, head2, carry);

            // append the remaining nodes of longer size list
            // to the result of same size lists
            result = AddLeftOverList (head1, current, result, carry);
        }
    }

    if (carry) {
        result = AddNode (result, 1);
    }

    return result;
}

int main() {
    Node *head1 = NULL;
    Node *head2 = NULL;

    head1 = AddNode(head1, 7);
    head1 = AddNode(head1, 8);
    head1 = AddNode(head1, 9);
    head1 = AddNode(head1, 2);
    head1 = AddNode(head1, 1);
    cout << "First list: ";
    PrintList (head1);

    head2 = AddNode(head2, 3);
    head2 = AddNode(head2, 2);
    head2 = AddNode(head2, 1);
    cout << "Second list: ";
    PrintList (head2);

    Node *result = AddLists (head1, head2);
    cout << "Result list: ";
    PrintList (result);
    return 0;
}