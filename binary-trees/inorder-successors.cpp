#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node* next;

        Node () {
            data = 0;
            left = NULL;
            right = NULL;
            next = NULL;
        }
};

void populateNextRecur(Node* root, Node** next_ref) {
    if (root == NULL)
        return;

    // move towards right
    populateNextRecur(root->right, next_ref);

    root->next = *next_ref;
    *next_ref = root;

    // move towards left
    populateNextRecur(root->left, next_ref);
}

void populateNext(Node* root) {
    Node *next = NULL;
    populateNextRecur(root, &next);
}

Node* newnode(int data) {
    Node *node = new Node();
    node->data = data;
    return node;
}

int main() {
    Node* root = newnode(10);
    root->left = newnode(8);
    root->right = newnode(12);
    root->left->left = newnode(3);

    // Populates nextRight pointer in all nodes
    populateNext(root);

    // Let us see the populated values
    Node* ptr = root->left->left;
    while (ptr) {
        // -1 is printed if there is no successor
        cout << "Next of " << ptr->data << ": "
            << (ptr->next ? ptr->next->data : -1) << endl;
        ptr = ptr->next;
    }

    return 0;
}