#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

// Definition for a binary tree node provided by LeetCode.
class Node {
    public:
        int val;
        Node *left;
        Node *right;
        Node() : val(0), left(nullptr), right(nullptr) {}
        Node(int x) : val(x), left(nullptr), right(nullptr) {}
        Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int minDiff = INT_MAX;
    Node* prev = nullptr;

    void inorder(Node* root) {
        if (root == nullptr)
            return;

        // Traverse left subtree
        inorder(root->left);

        // Process current node
        if (prev != nullptr) {
            minDiff = std::min(minDiff, root->val - prev->val);
        }
        prev = root; // Update previous node pointer

        // Traverse right subtree
        inorder(root->right);
    }

public:
    int getMinimumDifference(Node* root) {
        minDiff = INT_MAX;
        prev = nullptr;
        inorder(root);
        return minDiff;
    }
};

// Helper function to free allocated tree nodes to prevent memory leaks in tests
void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Solution sol;

    // Test Case 1:
    //      4
    //     / \
    //    2   6
    //   / \
    //  1   3
    // Expected Minimum Difference: |2 - 1| = 1 (or |3 - 2|, |4 - 3|) -> 1
    Node* root1 = new Node(4);
    root1->left = new Node(2);
    root1->right = new Node(6);
    root1->left->left = new Node(1);
    root1->left->right = new Node(3);

    std::cout << "Test 1 Output: " << sol.getMinimumDifference(root1) 
              << " | Expected: 1" << std::endl;

    // Test Case 2:
    //      1
    //       \
    //        48
    //       /  \
    //      12  49
    // Expected Minimum Difference: |49 - 48| = 1
    Node* root2 = new Node(1);
    root2->right = new Node(48);
    root2->right->left = new Node(12);
    root2->right->right = new Node(49);

    std::cout << "Test 2 Output: " << sol.getMinimumDifference(root2) 
              << " | Expected: 1" << std::endl;

    // Test Case 3:
    //      236
    //     /   \
    //   104   701
    //     \     \
    //     227   911
    // Expected Minimum Difference: |236 - 227| = 9
    Node* root3 = new Node(236);
    root3->left = new Node(104);
    root3->right = new Node(701);
    root3->left->right = new Node(227);
    root3->right->right = new Node(911);

    std::cout << "Test 3 Output: " << sol.getMinimumDifference(root3) 
              << " | Expected: 9" << std::endl;

    // Cleanup memory
    deleteTree(root1);
    deleteTree(root2);
    deleteTree(root3);

    return 0;
}