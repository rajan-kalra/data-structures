#include <iostream>
using namespace std;
 
class Node {
public:
	int data;
	Node* next;
};
 
Node* deleteList(Node* head) {
    if (head == NULL)
        return head;
    
    Node *curr = head;
    Node *temp;
    while (curr) {
        temp = curr;
        curr = curr->next;
        cout << "Deleting " << temp->data << endl;
        delete temp;
    }

    return curr;
}
 
void push(Node** head_ref, int new_data) {
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
 
int main() {
	Node* head = NULL;
	push(&head, 13);
	push(&head, 40);
	push(&head, 11);
	push(&head, 12);
	push(&head, 10);
 
	cout << "Deleting linked list start.." << endl;
	head = deleteList(head);
	cout << "Deleting linked list complete.";
}