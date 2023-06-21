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
 
Node* InsertAtEnd (Node *head, int data) {
	if (head == NULL) {
		Node *node = CreateNode(0);
		return node;
	}
 
	Node *node = CreateNode(0);
	Node *curr = head;
	while (curr->next)
		curr = curr->next;
	curr->next = node;
	return head;
}
 
Node* InsertAtStart (Node *head, int data) {
	if (head == NULL) {
		Node *node = CreateNode(0);
		return node;
	}
 
	Node *node = CreateNode(0);
	node->next = head;
	head = node;
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
 
int main() {
	Node *head = NULL;
	head = CreateNode(1);
	head->next = CreateNode(2);
	head->next->next = CreateNode(3);
	head->next->next->next = CreateNode(4);
	head->next->next->next->next = CreateNode(5);
	PrintList(head);
	//head = InsertAtStart(head, 0);
	//head = InsertAtEnd(head, 0);
	head = InsertAfter(head, 6);
	PrintList(head);
	return 0;
}