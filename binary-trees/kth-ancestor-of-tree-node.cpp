#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    Node* newNode(int data) {
        return new Node(data);
    }

    // Returns the kth ancestor's value, or -1 if it doesn't exist.
    int getKthAncestor(int target, int k) {
        int result = -1;
        findKthAncestor(root, target, k, result);
        return result;
    }

private:
    // Returns true if target is found in subtree rooted at node.
    // Decrements k on the way back up; captures ancestor value when k reaches 0.
    bool findKthAncestor(Node* node, int target, int& k, int& result) {
        if (node == nullptr)
            return false;

        if (node->data == target)
            return true;

        if (findKthAncestor(node->left, target, k, result) ||
            findKthAncestor(node->right, target, k, result)) {
            if (--k == 0)
                result = node->data;
            return true;
        }

        return false;
    }
};

void runTest(BinaryTree& tree, int target, int k, int expected) {
    int got = tree.getKthAncestor(target, k);
    cout << "target=" << target << ", k=" << k
         << " | expected=" << expected << ", got=" << got
         << " | " << (got == expected ? "PASS" : "FAIL") << "\n";
}

int main() {
    /* Construct the following binary tree
              1
             / \
            2   3
           / \
          4   5
         /
        7
    */
    BinaryTree tree;
    tree.root                           = tree.newNode(1);
    tree.root->left                     = tree.newNode(2);
    tree.root->right                    = tree.newNode(3);
    tree.root->left->left               = tree.newNode(4);
    tree.root->left->right              = tree.newNode(5);
    tree.root->left->left->left         = tree.newNode(7);

    runTest(tree,  7, 1,  4);  // parent of 7 is 4
    runTest(tree,  7, 2,  2);  // grandparent of 7 is 2
    runTest(tree,  7, 3,  1);  // great-grandparent of 7 is root (1)
    runTest(tree,  7, 4, -1);  // only 3 ancestors exist above 7
    runTest(tree,  5, 1,  2);  // parent of 5 is 2
    runTest(tree,  5, 2,  1);  // grandparent of 5 is root (1)
    runTest(tree,  4, 1,  2);  // parent of 4 is 2
    runTest(tree,  3, 1,  1);  // parent of 3 is root (1)
    runTest(tree,  1, 1, -1);  // root has no ancestor
    runTest(tree, 99, 1, -1);  // target not in tree

    return 0;
}