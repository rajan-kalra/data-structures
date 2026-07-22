#include <iostream>
#include <climits>

// Definition for a binary tree node.
class Node {
    public:
        int val;
        Node *left;
        Node *right;
        Node() : val(0), left(nullptr), right(nullptr) {}
        Node(int x) : val(x), left(nullptr), right(nullptr) {}
        Node(int x, Node *l, Node *r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    bool isValidBST(Node* root) {
        return validate(root, nullptr, nullptr);
    }

private:
    bool validate(Node* node, const int* minVal, const int* maxVal) {
        // Base case: an empty tree or null child is always valid
        if (node == nullptr) {
            return true;
        }

        // Violation check: node value must be strictly GREATER than minVal
        if (minVal != nullptr && node->val <= *minVal) {
            return false;
        }

        // Violation check: node value must be strictly LESS than maxVal
        if (maxVal != nullptr && node->val >= *maxVal) {
            return false;
        }

        // Recurse left: current node becomes upper bound (maxVal)
        // Recurse right: current node becomes lower bound (minVal)
        return validate(node->left, minVal, &(node->val)) &&
               validate(node->right, &(node->val), maxVal);
    }
};

// Helper function to free allocated tree memory
void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Solution solution;

    // Example 1: Valid BST
    //      2
    //     / \
    //    1   3
    Node* ex1 = new Node(2,
        new Node(1),
        new Node(3)
    );
    std::cout << "Example 1 Output: " << (solution.isValidBST(ex1) ? "true" : "false") << std::endl;
    // Expected: true

    // Example 2: Invalid BST
    //      5
    //     / \
    //    1   4
    //       / \
    //      3   6
    // (Invalid because node 4 is right child of 5, but 4 < 5)
    Node* ex2 = new Node(5,
        new Node(1),
        new Node(4, new Node(3), new Node(6))
    );
    std::cout << "Example 2 Output: " << (solution.isValidBST(ex2) ? "true" : "false") << std::endl;
    // Expected: false

    // Example 3: Subtree boundary violation
    //     10
    //    /  \
    //   5   15
    //      /  \
    //     6   20
    // (Invalid because node 6 is in right subtree of 10, but 6 < 10)
    Node* ex3 = new Node(10,
        new Node(5),
        new Node(15, new Node(6), new Node(20))
    );
    std::cout << "Example 3 Output: " << (solution.isValidBST(ex3) ? "true" : "false") << std::endl;
    // Expected: false

    // Cleanup memory
    deleteTree(ex1);
    deleteTree(ex2);
    deleteTree(ex3);

    return 0;
}