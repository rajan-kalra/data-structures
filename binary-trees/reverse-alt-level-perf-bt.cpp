#include <iostream>
using namespace std;

class Node {
    public:
        char key;
        Node *left;
        Node *right;

        Node() {
            key = '#';
            left = NULL;
            right = NULL;
        }
};

void preorder(Node *root1, Node* root2, int level) {
    if (root1 == NULL || root2==NULL)
        return;

    // Swap subtrees if level is even
    if (level % 2 == 0)
        swap(root1->key, root2->key);

    // Recur for left and right
    // subtrees (Note : left of root1
    // is passed and right of root2 in
    // first call and opposite
    // in second call.
    preorder(root1->left, root2->right, level + 1);
    preorder(root1->right, root2->left, level + 1);
}

void reverseAlternate(Node *root) {
    preorder(root->left, root->right, 0);
}

void printInorder(struct Node *root) {
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->key << " ";
    printInorder(root->right);
}

Node *newNode(int key) {
    Node *temp = new Node;
    temp->key = key;
    return temp;
}

int main() {
    struct Node *root = newNode('a');
    root->left = newNode('b');
    root->right = newNode('c');
    root->left->left = newNode('d');
    root->left->right = newNode('e');
    root->right->left = newNode('f');
    root->right->right = newNode('g');
    root->left->left->left = newNode('h');
    root->left->left->right = newNode('i');
    root->left->right->left = newNode('j');
    root->left->right->right = newNode('k');
    root->right->left->left = newNode('l');
    root->right->left->right = newNode('m');
    root->right->right->left = newNode('n');
    root->right->right->right = newNode('o');

    cout << "Inorder Traversal of given tree\n";
    printInorder(root);

    reverseAlternate(root);

    cout << "\n\nInorder Traversal of modified tree\n";
    printInorder(root);
    return 0;
}