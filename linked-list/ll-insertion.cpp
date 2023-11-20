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
 
Node* createNode (int data) {
	Node *node = new Node(data);
	return node;
}
 
Node* insertAfter (Node *head, int after) {
	if (head == NULL) {
		cout << "Empty list!";
		return NULL;
	}
 
	Node *node = createNode(100);
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
		Node *node = createNode(0);
		return node;
	}
 
	Node *node = createNode(0);
	Node *curr = head;
	while (curr->next)
		curr = curr->next;
	curr->next = node;
	return head;
}
 
Node* InsertAtStart (Node *head, int data) {
	if (head == NULL) {
		Node *node = createNode(0);
		return node;
	}
 
	Node *node = createNode(0);
	node->next = head;
	head = node;
	return head;
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
 
int main() {
	Node *head = NULL;
	head = createNode(1);
	head->next = createNode(2);
	head->next->next = createNode(3);
	head->next->next->next = createNode(4);
	head->next->next->next->next = createNode(5);
	printList(head);
	//head = InsertAtStart(head, 0);
	//head = InsertAtEnd(head, 0);
	head = insertAfter(head, 6);
	printList(head);
	return 0;
}