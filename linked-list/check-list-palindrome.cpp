#include <iostream>
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
 
Node* InsertAfter (Node *head, int after) {
    if (head == NULL) {
        cout << "Empty list!";
        return NULL;
    }

    Node *node = CreateNode(100);
    Node *curr = head;

    // 'after' node is first node
    while (curr && curr->data != after) {
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << after << " not found" << endl;
        return head;
    }

    node->next = curr->next;
    curr->next = node;
    return head;
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

Node* reverseList (Node *head) {
	Node *curr = head;
	Node *prev = NULL;
	Node *next;

	while (curr) {
        next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}

bool compareLists (Node *head1, Node *head2) {
    while (head1 && head2 && head1->data == head2->data) {
        head1 = head1->next;
        head2 = head2->next;
    }

    if (head1 == NULL && head2 == NULL)
        return true;
    else
    return false;
}

bool isListPalindrome (Node *head) {
    if (head == NULL || head->next == NULL)
        return false;

    Node *fast = head;
    Node *slow = head;
    Node *prevSlow = NULL;
    Node *mid = NULL;
    Node *secondHalf;

    while (fast && fast->next) {
        prevSlow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast == NULL) {
        prevSlow->next = NULL;
        secondHalf = slow;
    } else {
        secondHalf = slow->next;
        prevSlow->next = NULL;
        mid = slow;
    }

    Node *newSecondHalfHead = reverseList (secondHalf);

    bool result = compareLists (head, newSecondHalfHead);
    secondHalf = reverseList (newSecondHalfHead);

    if (mid) {
        prevSlow->next = mid;
        mid->next = secondHalf;
    } else {
        prevSlow->next = secondHalf;
    }

    return result;
}
 
int main() {
    Node *head = NULL;
    head = CreateNode(1);
    head->next = CreateNode(2);
    head->next->next = CreateNode(3);
    head->next->next->next = CreateNode(3);
    head->next->next->next->next = CreateNode(2);
    head->next->next->next->next->next = CreateNode(1);
    cout << "List before operations: "; PrintList(head);

    isListPalindrome(head) ? cout << "Given list represents a palindrome!" << endl : cout << "Given list doesn't represent a palindrome!" << endl;

    cout << "List before operations: "; PrintList(head);

    return 0;
}