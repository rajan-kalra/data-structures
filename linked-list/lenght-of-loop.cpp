#include <iostream>
#include <unordered_set>
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

bool isLoopPresentUsingRabbitAndHare (Node *head) {
    if (head == NULL)
        return false;

    Node *fast = head;
    Node *slow = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }

    return false;
}

int getLoopLength (Node *head) {
    if (head == NULL || head->next == NULL)
        return 0;

    Node *fast = head;
    Node *slow = head;
    Node *loopNode = NULL;
    int count = 0;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            loopNode = slow;
            break;
        }
    }

    if (loopNode != NULL) {
        count = 1;
        Node *curr = loopNode->next;
        while (curr != loopNode) {
            count++;
            curr = curr->next;
        }
    }

    return count;
}


int main() {
    Node *head = NULL;
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    head->next->next->next->next->next = head->next->next;

    //PrintList (head);
    cout << "Length of loop: " << getLoopLength(head);

    return 0;
}