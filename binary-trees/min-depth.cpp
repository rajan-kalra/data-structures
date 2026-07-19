#include <iostream>
#include <algorithm>
#include <string>

// Definition for a binary tree node.
class Node {
    public:
        int val;
        Node* left;
        Node* right;
        
        Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int minDepth(Node* root) {
        // Base case: if the tree is empty, the depth is 0
        if (root == nullptr) {
            return 0;
        }
        
        // If there is no left child, we must check the right subtree path
        if (root->left == nullptr) {
            return 1 + minDepth(root->right);
        }
        
        // If there is no right child, we must check the left subtree path
        if (root->right == nullptr) {
            return 1 + minDepth(root->left);
        }
        
        // If both children exist, take the minimum depth between the two paths
        return 1 + std::min(minDepth(root->left), minDepth(root->right));
    }
};

// Helper function to cleanly delete the tree and prevent memory leaks
void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Helper function to print the result of a test case with expected vs actual output
void printResult(const std::string& name, int expected, int actual) {
    std::cout << name << ": "
              << "Expected = " << expected << ", "
              << "Actual = " << actual << " -> "
              << (actual == expected ? "PASSED" : "FAILED") << "\n";
}

int main() {
    Solution solution;

    // --- TEST CASE 1: Empty Tree ---
    // Expected Output: 0
    Node* root1 = nullptr;
    printResult("Test Case 1 (Empty Tree)", 0, solution.minDepth(root1));


    // --- TEST CASE 2: Single Node Tree ---
    // Expected Output: 1
    Node* root2 = new Node(1);
    printResult("Test Case 2 (Single Node)", 1, solution.minDepth(root2));
    deleteTree(root2);


    // --- TEST CASE 3: Standard Unbalanced Tree (LeetCode Example 1) ---
    //       3
    //      / \
    //     9  20
    //       /  \
    //      15   7
    // Nearest leaf is 9, path length = 2 (nodes 3 -> 9)
    // Expected Output: 2
    Node* root3 = new Node(3);
    root3->left = new Node(9);
    root3->right = new Node(20);
    root3->right->left = new Node(15);
    root3->right->right = new Node(7);
    
    printResult("Test Case 3 (Standard Tree)", 2, solution.minDepth(root3));
    deleteTree(root3);


    // --- TEST CASE 4: The One-Sided Trap (LeetCode Example 2) ---
    //   2
    //    \
    //     3
    //      \
    //       4
    //        \
    //         5
    //          \
    //           6
    // Root node 2 has no left child, but it's not a leaf. We must evaluate the right path.
    // Expected Output: 5
    Node* root4 = new Node(2);
    root4->right = new Node(3);
    root4->right->right = new Node(4);
    root4->right->right->right = new Node(5);
    root4->right->right->right->right = new Node(6);
    
    printResult("Test Case 4 (One-Sided Trap)", 5, solution.minDepth(root4));
    deleteTree(root4);

    return 0;
}