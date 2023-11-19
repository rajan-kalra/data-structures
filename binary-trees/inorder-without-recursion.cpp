#include <iostream>
#include <stack>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node (int k) {
            data = k;
            left = NULL;
            right = NULL;
        }
};

Node* CreateNode (int k) {
    Node *node = new Node(k);
    return node;
}

void inorder (Node* root) {
    if (root == NULL)
        return;

    stack<Node*> s;
    Node *current = root;
    // keep looping until current is not null
    // or stack is not empty
    while ((current) || (s.empty() == false)) {
        // if current is not null, push
        // current to stack & move towards left
        if (current) {
            s.push (current);
            current = current->left;
        // if current is current is NULL & stack is not empty,
        // pop the top of stack & move towards right
        } else {
            current = s.top();
            s.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }
}

int main() {
    Node *root = CreateNode (1);
    root->left = CreateNode (2);
    root->right = CreateNode (3);
    root->left->left = CreateNode (4);
    root->left->right = CreateNode (5);

    inorder (root);

    return 0;
}