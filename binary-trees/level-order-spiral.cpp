#include <iostream>
#include <stack>
using namespace std;

class Node {
    public:
        int data;
        Node *left, *right;

        Node () {
            data = 0;
            left = NULL;
            right = NULL;
        }
};

void printSpiral( Node* root) {
    if (root == NULL)
        return;

    stack<struct Node*> s1;
    stack<struct Node*> s2;

    s1.push(root);

    while (s1.empty() == false || s2.empty() == false) {
        // Print nodes of current level from s1 and push nodes of
        // next level to s2
        while (s1.empty() == false) {
            Node* temp = s1.top();
            s1.pop();
            cout << temp->data << " ";

            // Note that is right is pushed before left
            if (temp->right)
                s2.push(temp->right);
            if (temp->left)
                s2.push(temp->left);
        }

        // Print nodes of current level from s2 and push nodes of
        // next level to s1
        while (s2.empty() == false) {
            Node* temp = s2.top();
            s2.pop();
            cout << temp->data << " ";

            // Note that is left is pushed before right
            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }
    }
}

struct Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    return (node);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    cout << "Spiral Order traversal of binary tree is: ";
    printSpiral(root);

    return 0;
}