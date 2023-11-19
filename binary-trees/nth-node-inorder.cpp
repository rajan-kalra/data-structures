#include <iostream>

class Node {
    public:
        int data;
        struct Node* left;
        struct Node* right;
        Node () {
            data = 0;
            left = NULL;
            right = NULL;
        }
};

struct Node* newNode(int data) {
    Node *node = new Node();
    node->data = data;
    return node;
}

void NthInorder(Node* root, int &n) { 
    if (root == NULL)
        return;
    
    // traverse the left tree
    NthInorder(root->left, n);

    // at the inorder traversal step, compute the n & print the element
    n--;
    // important to understand that this check must be done here
    if (n == 0) {
        printf("Required element: %d\n", root->data);
        return;
    }

    // traverse the right tree
    NthInorder(root->right, n);
}

int main() {
    Node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);

    int n = 1;
    NthInorder(root, n);
    n = 2;
    NthInorder(root, n);
    n = 3;
    NthInorder(root, n);
    n = 4;
    NthInorder(root, n);
    n = 5;
    NthInorder(root, n);
    return 0;
}
