#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

// Definition for a binary tree node.
struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    int dfs(Node* node, int currentMin, int currentMax) {
        if (node == nullptr) {
            // Base case: return the max difference along this path
            return currentMax - currentMin;
        }

        // Update the running minimum and maximum for the path including the current node
        currentMin = std::min(currentMin, node->val);
        currentMax = std::max(currentMax, node->val);

        // Recurse down left and right subtrees and return the maximum difference found
        int leftDiff = dfs(node->left, currentMin, currentMax);
        int rightDiff = dfs(node->right, currentMin, currentMax);

        return std::max(leftDiff, rightDiff);
    }

public:
    int maxAncestorDiff(Node* root) {
        if (root == nullptr)
            return 0;
        return dfs(root, root->val, root->val);
    }
};

// Helper function to build a tree from level-order vector representation (with -1 as nullptr)
Node* buildTree(const std::vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    Node* root = new Node(nodes[0]);
    std::queue<Node*> q;
    q.push(root);

    size_t i = 1;
    while (!q.empty() && i < nodes.size()) {
        Node* current = q.front();
        q.pop();

        // Left child
        if (i < nodes.size() && nodes[i] != -1) {
            current->left = new Node(nodes[i]);
            q.push(current->left);
        }
        i++;

        // Right child
        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new Node(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

// Helper function to free memory
void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Solution sol;

    // Test Case 1: Standard tree
    // Input: [8,3,10,1,6,-1,14,-1,-1,4,7,13]
    // Expected output: 7 (e.g., |8 - 1| = 7 or |8 - 15| = 7)
    std::vector<int> tree1 = {8, 3, 10, 1, 6, -1, 14, -1, -1, 4, 7, 13};
    Node* root1 = buildTree(tree1);
    std::cout << "Test 1 Output: " << sol.maxAncestorDiff(root1) << " (Expected: 7)" << std::endl;
    deleteTree(root1);

    // Test Case 2: Skewed/Linear tree
    // Input: [1,-1,2,-1,0,3]
    // Expected output: 3 (|0 - 3| = 3)
    std::vector<int> tree2 = {1, -1, 2, -1, 0, 3};
    Node* root2 = buildTree(tree2);
    std::cout << "Test 2 Output: " << sol.maxAncestorDiff(root2) << " (Expected: 3)" << std::endl;
    deleteTree(root2);

    // Test Case 3: Two-node tree
    // Input: [5, 2]
    // Expected output: 3
    std::vector<int> tree3 = {5, 2};
    Node* root3 = buildTree(tree3);
    std::cout << "Test 3 Output: " << sol.maxAncestorDiff(root3) << " (Expected: 3)" << std::endl;
    deleteTree(root3);

    return 0;
}