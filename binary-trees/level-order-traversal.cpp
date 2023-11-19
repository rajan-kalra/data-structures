#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node () {
            data = 0;
            left = NULL;
            right = NULL;
        }
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    return node;
}

void printLevelOrder(Node* root) {
    if (root == NULL) {
        cout << "Emtpy tree!" << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (q.empty() == false) {
        // pop a node
        Node *curr = q.front();
        q.pop();
        
        // check if popped node has left, enqueue it
        if (curr->left)
            q.push(curr->left);

        // check if popped node has right, enqueue it
        if (curr->right)
            q.push(curr->right);
        
        cout << curr->data << " ";
    }
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Level Order traversal of binary tree: ";
    printLevelOrder(root);

    return 0;
}