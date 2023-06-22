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

bool isLoopPresentUsingHashing (Node *head) {
	if (head == NULL)
		return false;

	unordered_set<Node*> visited;

	Node *curr = head;
	while (curr) {
		if (visited.find(curr) != visited.end())
			return true;
		visited.insert(curr);
		curr = curr->next;
	}

	return false;
}

int main() {
	Node *head = NULL;
	head = CreateNode(1);
	head->next = CreateNode(2);
	head->next->next = CreateNode(3);
	head->next->next->next = CreateNode(4);
	head->next->next->next->next = CreateNode(5);

	head->next->next->next->next->next = head->next->next;

	//PrintList (head);

	//isLoopPresentUsingRabbitAndHare(head) ? cout << "Loop is present!" : cout << "Loop is not present!";
	isLoopPresentUsingHashing(head) ? cout << "Loop is present!" : cout << "Loop is not present!";

	return 0;
}