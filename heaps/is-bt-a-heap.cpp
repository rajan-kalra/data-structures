#include <iostream>
using namespace std;

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int k) {
    struct Node* node = new Node;
    node->key = k;
    node->right = node->left = NULL;
    return node;
}

int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isCompleteBinaryTree(struct Node* root, int index, int numOfNodes) {
    // an empty tree is a CBT
    if (root == NULL)
        return true;

    /**
     * If index current node index is more than number
     * of nodes in tree, then tree is not complete
     */
    if (index >= numOfNodes)
        return false;

    bool left = isCompleteBinaryTree(root->left, 2 * index + 1, numOfNodes);
    bool right = isCompleteBinaryTree(root->right, 2 * index + 2, numOfNodes);

    // Recur for left and right subtrees
    return left && right;
}

bool isMaxOrdered(struct Node* root) {
    // leaf node itself is a heap
    if (root->left == NULL && root->right == NULL)
        return true;
    
    // if only left child exists
    if (root->right == NULL) {
        // just check if root's value is greater than child's value
        return root->key >= root->left->key;
    // when both child exists
    } else {
        // check root's value must be greater than left & right child
        if (root->key >= root->left->key && root->key >= root->right->key)
            return isMaxOrdered(root->left) && isMaxOrdered(root->right);
        else
            return false;
    }
}

bool isHeap(struct Node* root) {
    int node_count = countNodes(root);
    int index = 0;

    // given tree is a heap is its a CBT & its ordered
    if (isCompleteBinaryTree(root, index, node_count) && isMaxOrdered(root))
        return true;
    return false;
}

int main() {
    struct Node* root = NULL;
    root = newNode(10);
    root->left = newNode(9);
    root->right = newNode(8);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    root->left->left->left = newNode(3);
    root->left->left->right = newNode(2);
    root->left->right->left = newNode(1);

    // Function call
    if (isHeap(root))
        cout << "Given binary tree is a Heap\n";
    else
        cout << "Given binary tree is not a Heap\n";

    return 0;
}