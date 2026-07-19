#include <iostream>
#include <vector>
#include <cassert>

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
    int sumRootToLeaf(Node* node, int currentSum) {
        if (node == nullptr)
            return 0;
        
        currentSum = currentSum * 10 + node->val;
        
        // If it's a leaf node, return the accumulated path number
        if (node->left == nullptr && node->right == nullptr) {
            return currentSum;
        }
        
        // Sum values from both left and right branches
        return sumRootToLeaf(node->left, currentSum) + sumRootToLeaf(node->right, currentSum);
    }

public:
    int sumNumbers(Node* root) {
        return dfs(root, 0);
    }
};

// Helper function to free memory allocated for the tree
void deleteTree(Node* root) {
    if (root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Solution solution;

    // Test Case 1:
    //      1
    //     / \
    //    2   3
    // Paths: 12 + 13 = 25
    Node* test1 = new Node(1);
    test1->left = new Node(2);
    test1->right = new Node(3);

    int result1 = solution.sumNumbers(test1);
    std::cout << "Test Case 1 Output: " << result1 << " | Expected: 25" << std::endl;
    assert(result1 == 25);

    // Test Case 2:
    //        4
    //       / \
    //      9   0
    //     / \
    //    5   1
    // Paths: 495 + 491 + 40 = 1026
    Node* test2 = new Node(4);
    test2->left = new Node(9);
    test2->right = new Node(0);
    test2->left->left = new Node(5);
    test2->left->right = new Node(1);

    int result2 = solution.sumNumbers(test2);
    std::cout << "Test Case 2 Output: " << result2 << " | Expected: 1026" << std::endl;
    assert(result2 == 1026);

    // Test Case 3 (Single Node):
    //    9
    // Path: 9
    Node* test3 = new Node(9);

    int result3 = solution.sumNumbers(test3);
    std::cout << "Test Case 3 Output: " << result3 << " | Expected: 9" << std::endl;
    assert(result3 == 9);

    // Clean up memory
    deleteTree(test1);
    deleteTree(test2);
    deleteTree(test3);

    std::cout << "\nAll test cases passed successfully!" << std::endl;

    return 0;
}