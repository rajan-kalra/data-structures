#include <iostream>
#include <algorithm>
#include <utility>

// Definition for a binary tree node.
class Node {
    public:
        int val;
        Node* left;
        Node* right;
        
        Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    // Returns {depth, LCA}
    std::pair<int, Node*> lcaDeepestLeavesHelper(Node* node) {
        if (node == nullptr) {
            return {0, nullptr};
        }

        auto left = lcaDeepestLeavesHelper(node->left);
        auto right = lcaDeepestLeavesHelper(node->right);

        if (left.first == right.first) {
            // Equal depths mean current node is the LCA for this subtree
            return {left.first + 1, node};
        } else if (left.first > right.first) {
            // Left subtree is deeper
            return {left.first + 1, left.second};
        } else {
            // Right subtree is deeper
            return {right.first + 1, right.second};
        }
    }

public:
    Node* lcaDeepestLeaves(Node* root) {
        return lcaDeepestLeavesHelper(root).second;
    }
};

// Helper function to free allocated tree memory
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    Solution solution;

    // -------------------------------------------------------------
    // Test Case 1: [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]
    //
    //              3
    //            /   \
    //           5     1
    //          / \   / \
    //         6   2 0   8
    //            / \
    //           7   4
    //
    // Deepest leaves are 7 and 4 (depth 4). Their LCA is node 2.
    // -------------------------------------------------------------
    Node* root1 = new Node(3);
    root1->left = new Node(5);
    root1->right = new Node(1);
    root1->left->left = new Node(6);
    root1->left->right = new Node(2);
    root1->right->left = new Node(0);
    root1->right->right = new Node(8);
    root1->left->right->left = new Node(7);
    root1->left->right->right = new Node(4);

    Node* res1 = solution.lcaDeepestLeaves(root1);
    std::cout << "Test 1 Expected: 2 | Result: " << (res1 ? res1->val : -1) << std::endl;

    // -------------------------------------------------------------
    // Test Case 2: [1]
    // Single node tree. Deepest leaf is 1, LCA is node 1.
    // -------------------------------------------------------------
    Node* root2 = new Node(1);

    Node* res2 = solution.lcaDeepestLeaves(root2);
    std::cout << "Test 2 Expected: 1 | Result: " << (res2 ? res2->val : -1) << std::endl;

    // -------------------------------------------------------------
    // Test Case 3: [0, 1, 3, null, 2]
    //
    //          0
    //         / \
    //        1   3
    //         \
    //          2
    //
    // Deepest leaf is 2 (depth 3). LCA is node 2 itself.
    // -------------------------------------------------------------
    Node* root3 = new Node(0);
    root3->left = new Node(1);
    root3->right = new Node(3);
    root3->left->right = new Node(2);

    Node* res3 = solution.lcaDeepestLeaves(root3);
    std::cout << "Test 3 Expected: 2 | Result: " << (res3 ? res3->val : -1) << std::endl;

    // Cleanup memory
    freeTree(root1);
    freeTree(root2);
    freeTree(root3);

    return 0;
}