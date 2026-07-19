#include <iostream>
#include <vector>

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
    int sumRootToLeafBinaryNumbers(Node* root, int currentSum) {
        if (root == nullptr)
            return 0;

        // Shift left by 1 (multiply by 2) and append current node's bit value
        currentSum = (currentSum << 1) | root->val;

        // If it's a leaf node, return the completed binary number value
        if (root->left == nullptr && root->right == nullptr) {
            return currentSum;
        }

        // Sum up the results from both subtrees
        return sumRootToLeafBinaryNumbers(root->left, currentSum) + sumRootToLeafBinaryNumbers(root->right, currentSum);
    }

public:
    int sumRootToLeaf(Node* root) {
        return sumRootToLeafBinaryNumbers(root, 0);
    }
};

// Helper function to free allocated tree memory
void deleteTree(Node* root) {
    if (root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    /*
     * Constructing Example 1:
     *         1
     *       /   \
     *      0     1
     *     / \   / \
     *    0   1 0   1
     *
     * Binary Paths:
     * 1 -> 0 -> 0 = 100 (4)
     * 1 -> 0 -> 1 = 101 (5)
     * 1 -> 1 -> 0 = 110 (6)
     * 1 -> 1 -> 1 = 111 (7)
     * Total Sum = 4 + 5 + 6 + 7 = 22
     */

    Node* root = new Node(1);
    root->left = new Node(0);
    root->right = new Node(1);
    root->left->left = new Node(0);
    root->left->right = new Node(1);
    root->right->left = new Node(0);
    root->right->right = new Node(1);

    Solution solution;
    int result = solution.sumRootToLeaf(root);

    std::cout << "Sum of Root-to-Leaf Binary Numbers: " << result << std::endl;
    // Expected Output: 22

    // Clean up memory
    deleteTree(root);

    return 0;
}