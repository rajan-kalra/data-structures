#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node () {
            data = 0;
            left = NULL;
            right = NULL;
        }
};

Node* newNode(int val) {
    Node* temp = new Node();
    temp->data = val;
    return temp;
}

void inorderSuccessor (Node *root, Node *target_node, Node **next) {
    if(root == NULL)
        return;

    inorderSuccessor (root->right, target_node, next);

    if (root->data == target_node->data) {
        if(*next == NULL)
            cout << "inorder successor of " << root->data << " is: null\n";
        else
            cout << "inorder successor of " << root->data << " is: " << (*next)->data << "\n";
    }
    *next = root;

    inorderSuccessor (root->left, target_node, next);
}

int main() {
    // Let's construct the binary tree
    //		 1
    // / \
    // 2	 3
    // / \ / \
    // 4 5 6 7
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Case 1
    Node *next = NULL;
    inorderSuccessor (root, root, &next);

    // case 2
    next = NULL;
    inorderSuccessor (root, root->left->left, &next);

    // case 3
    next = NULL;
    inorderSuccessor (root, root->right->right, &next);

    return 0;
}