#include <iostream>
#include <vector>
#include <queue>

// Definition for a binary tree node (Standard LeetCode definition)
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
public:
    // Approach 1: Iterative (O(1) Space)
    Node* searchBST(Node* root, int val) {
        Node* current = root;
        while (current != nullptr && current->val != val) {
            if (val < current->val) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return current;
    }

    // Approach 2: Recursive (O(h) Space due to call stack)
    Node* searchBSTRecursive(Node* root, int val) {
        if (root == nullptr || root->val == val) {
            return root;
        }
        return val < root->val ? searchBSTRecursive(root->left, val)
                               : searchBSTRecursive(root->right, val);
    }
};

// ============================================================================
// HELPER FUNCTIONS FOR TESTING
// ============================================================================

// Inserts a value into a BST
Node* insertBST(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);
    
    if (val < root->val) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

// Level-order traversal print for visual inspection
void printTree(Node* root) {
    if (!root) {
        std::cout << "[]\n";
        return;
    }
    std::queue<Node*> q;
    q.push(root);
    std::cout << "[";
    bool first = true;
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (!first) std::cout << ", ";
        first = false;

        if (curr) {
            std::cout << curr->val;
            q.push(curr->left);
            q.push(curr->right);
        } else {
            // Optional: comment out if you prefer skipping nulls in output
            // std::cout << "null"; 
        }
    }
    std::cout << "]\n";
}

// Helper to free allocated memory
void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// ============================================================================
// MAIN FUNCTION WITH TEST CASES
// ============================================================================

int main() {
    Solution solver;

    // ------------------------------------------------------------------------
    // Test Case 1: Value exists in the tree
    // Tree Structure:
    //        4
    //       / \
    //      2   7
    //     / \
    //    1   3
    // Search target: 2
    // ------------------------------------------------------------------------
    Node* root1 = nullptr;
    std::vector<int> values1 = {4, 2, 7, 1, 3};
    for (int v : values1) {
        root1 = insertBST(root1, v);
    }

    int target1 = 2;
    Node* result1 = solver.searchBST(root1, target1);

    std::cout << "Test Case 1: Target " << target1 << " -> " << (result1 ? "true" : "false") << "\n";

    // ------------------------------------------------------------------------
    // Test Case 2: Value does NOT exist in the tree
    // Search target: 5
    // ------------------------------------------------------------------------
    int target2 = 5;
    Node* result2 = solver.searchBST(root1, target2);

    std::cout << "Test Case 2: Target " << target2 << " -> " << (result2 ? "true" : "false") << "\n";

    // ------------------------------------------------------------------------
    // Test Case 3: Searching in an empty tree
    // ------------------------------------------------------------------------
    Node* root3 = nullptr;
    int target3 = 10;
    Node* result3 = solver.searchBST(root3, target3);

    std::cout << "Test Case 3 (Empty Tree): Target " << target3 << " -> " << (result3 ? "true" : "false") << "\n";

    // Clean up memory
    deleteTree(root1);
    deleteTree(root3);

    return 0;
}