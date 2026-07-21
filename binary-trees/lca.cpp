#include <iostream>
using namespace std;
 
class Node {
public:
    Node *left, *right;
    int key;
    Node () : left(NULL), right(NULL), key(0) {}
};
 
Node* newNode(int key) {
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
 
Node *lca(Node *root, int n1, int n2) {
    if (root == nullptr || root->key == n1 || root->key == n2)
        return root;

    Node *left = lca(root->left, n1, n2);
    Node *right = lca(root->right, n1, n2);

    // 1. if root is any one of node we are looking, we
    // return the root directly without looking further down. Base case.
    // 2. if both left & right returns NULL, we return NULL
    // 3. if any one of left or right is NULL, we return the other one
    // 4. if none of left & right is NULL, this implies its a LCA
    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else
        return root;
}
 
// Driver program to test above functions
int main()
{
    // Let us create binary tree given in the above example
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    Node *ancestor = NULL;
    ancestor = lca(root, 4, 5);
    if (ancestor)
        cout << "LCA(4, 5): " << ancestor->key << endl;

    ancestor = lca(root, 4, 6);
    if (ancestor)
        cout << "LCA(4, 6): " << ancestor->key << endl;

    ancestor = lca(root, 4, 7);
    if (ancestor)
        cout << "LCA(4, 7): " << ancestor->key << endl;

    ancestor = lca(root, 5, 6);
    if (ancestor)
        cout << "LCA(5, 6): " << ancestor->key << endl;

    ancestor = lca(root, 5, 7);
    if (ancestor)
        cout << "LCA(5, 7): " << ancestor->key << endl;

    ancestor = lca(root, 2, 3);
    if (ancestor)
        cout << "LCA(2, 3): " << ancestor->key << endl;

    ancestor = lca(root, 2, 7);
    if (ancestor)
        cout << "LCA(2, 7): " << ancestor->key << endl;

    ancestor = lca(root, 2, 5);
    if (ancestor)
        cout << "LCA(2, 5): " << ancestor->key << endl;

    return 0;
}