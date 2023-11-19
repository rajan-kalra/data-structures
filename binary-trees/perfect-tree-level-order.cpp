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

Node *newNode(int data) {
    Node *node = new Node;
    node->data = data;
    return node;
}

void printSpecificLevelOrder(Node *root) {
    // check if root itself is NULL
    if (root == NULL)
        return;

    cout << root->data << " ";

    // check is first level itself is NULL, as
    // its a perfect binary tree & if left is NULL
    // right must also be NULL
    if (root->left == NULL)
        return;

    // if left is not NULL, then left & right both exist
    Node *first = root->left;
    Node *second = root->right;

    queue<Node*> q;
    q.push(first);
    q.push (second);

    while (q.empty() == false) {
        // dequeue 2 nodes at a time
        first = q.front();
        q.pop();
        second = q.front();
        q.pop();
        
        // print dequeued nodes
        cout << first->data << " ";
        cout << second->data << " ";
        
        /**
         * here any positive check would mean
         * the next level exists, if next level
         * exists push in following order
         */
        if (first->left) {
            q.push(first->left);
            q.push(second->right);
            q.push(first->right);
            q.push(second->left);
        }
    }
}

int main() {
    //Perfect Binary Tree of Height 4
    Node *root = newNode(1);
    root->left	 = newNode(2);
    root->right	 = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);
    root->right->left->left = newNode(12);
    root->right->left->right = newNode(13);
    root->right->right->left = newNode(14);
    root->right->right->right = newNode(15);

    root->left->left->left->left = newNode(16);
    root->left->left->left->right = newNode(17);
    root->left->left->right->left = newNode(18);
    root->left->left->right->right = newNode(19);
    root->left->right->left->left = newNode(20);
    root->left->right->left->right = newNode(21);
    root->left->right->right->left = newNode(22);
    root->left->right->right->right = newNode(23);
    root->right->left->left->left = newNode(24);
    root->right->left->left->right = newNode(25);
    root->right->left->right->left = newNode(26);
    root->right->left->right->right = newNode(27);
    root->right->right->left->left = newNode(28);
    root->right->right->left->right = newNode(29);
    root->right->right->right->left = newNode(30);
    root->right->right->right->right = newNode(31);

    cout << "Specific Level Order traversal of binary tree is \n";
    printSpecificLevelOrder(root);

    return 0;
}