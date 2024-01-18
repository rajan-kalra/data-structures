#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node (int d) {
            data = d;
            next = NULL;
        }
};

void removeLoop(Node* loop_node, Node* head) {
    Node* ptr1 = loop_node;
    Node* ptr2 = loop_node;
    Node* prev_ptr2 = NULL;

    // STEP 2: Count the number of nodes in loop
    int k = 1;
    while (ptr1->next != ptr2) {
        ptr1 = ptr1->next;
        k++;
    }

    // STEP 3.a: Fix one pointer to head
    ptr1 = head;
    // STEP 3.b: And the other pointer to k nodes after head
    ptr2 = head;
    for (int i = 0; i < k; i++)
        ptr2 = ptr2->next;

    /* STEP 4: Move both the pointers at the same pace, they will meet at loop starting node */
    while (ptr2 != ptr1) {
        ptr1 = ptr1->next;
        // maintaining the previous of ptr2 to mark its next as NULL later
        prev_ptr2 = ptr2;
        ptr2 = ptr2->next;
    }

    // Get pointer to the last node
    while (ptr2->next != ptr1)
        ptr2 = ptr2->next;

    /* STEP 5: Set the next node of the loop ending node to fix the loop */
    prev_ptr2->next = NULL;
}

int detectAndRemoveLoop(Node* head) {
    Node *slow_p = head;
    Node *fast_p = head;

    // STEP 1: Iterate and find if loop exists or not
    while (fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;

        /* If slow_p and fast_p meet at some point then there is a loop */
        if (slow_p == fast_p) {
            removeLoop(slow_p, head);

            /* Return 1 to indicate that loop was found & removed */
            return 1;
        }
    }

    /* Return 0 to indicate that no loop was found */
    return 0;
}

void printList(struct Node* node) {
    // Print the list after loop removal
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

struct Node* newNode(int key) {
    Node *temp = new Node(key);
    return temp;
}

int main() {
    Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    detectAndRemoveLoop(head);

    cout << "Linked List after removing loop \n";
    printList(head);
    return 0;
}
