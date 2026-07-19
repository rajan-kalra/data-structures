#include <iostream>
#include <algorithm>
#include <vector>
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
    int maxDepth(Node* root) {
        // Base case: if the tree is empty, its depth is 0
        if (root == nullptr) {
            return 0;
        }
        
        // Recursively find the depth of the left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        // The overall depth is 1 (for the current node) plus the maximum of the two depths
        return 1 + std::max(leftDepth, rightDepth);
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
    printResult("Test Case 1 (Empty Tree)", 0, solution.maxDepth(root1));


    // --- TEST CASE 2: Single Node Tree ---
    // Expected Output: 1
    Node* root2 = new Node(1);
    printResult("Test Case 2 (Single Node)", 1, solution.maxDepth(root2));
    deleteTree(root2);


    // --- TEST CASE 3: Balanced Normal Tree ---
    //       3
    //      / \
    //     9  20
    //       /  \
    //      15   7
    // Expected Output: 3
    Node* root3 = new Node(3);
    root3->left = new Node(9);
    root3->right = new Node(20);
    root3->right->left = new Node(15);
    root3->right->right = new Node(7);
    
    printResult("Test Case 3 (Normal Tree)", 3, solution.maxDepth(root3));
    deleteTree(root3);


    // --- TEST CASE 4: Skewed Tree (Line / Linked List Style) ---
    //   1
    //    \
    //     2
    //      \
    //       3
    //        \
    //         4
    // Expected Output: 4
    Node* root4 = new Node(1);
    root4->right = new Node(2);
    root4->right->right = new Node(3);
    root4->right->right->right = new Node(4);
    
    printResult("Test Case 4 (Skewed Tree)", 4, solution.maxDepth(root4));
    deleteTree(root4);

    return 0;
}