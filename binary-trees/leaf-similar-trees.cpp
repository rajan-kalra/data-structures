#include <iostream>
#include <vector>

// Definition for a binary tree node.
class Node {
    public:
        int val;
        Node* left;
        Node* right;
        
        Node(int x) : val(x), left(nullptr), right(nullptr) {}
        Node(int x, Node* left, Node* right) : val(x), left(left), right(right) {}
};

class Solution {
private:    
    // Helper function to perform DFS and collect leaf node values
    void collectLeaves(Node* root, std::vector<int>& leaves) {
        if (root == nullptr)
            return;
        
        // If it's a leaf node, record its value
        if (root->left == nullptr && root->right == nullptr) {
            leaves.push_back(root->val);
            return;
        }
        
        // Traverse left and right subtrees
        collectLeaves(root->left, leaves);
        collectLeaves(root->right, leaves);
    }

public:
    bool leafSimilar(Node* root1, Node* root2) {
        std::vector<int> leaves1;
        std::vector<int> leaves2;
        
        collectLeaves(root1, leaves1);
        collectLeaves(root2, leaves2);
        
        // Standard vector comparison evaluates size and elements sequentially
        return leaves1 == leaves2;
    }
};

// Helper function to quickly clean up allocated memory
void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Solution solution;

    // --- TEST CASE 1: Leaf-Similar Trees ---
    // Tree 1 Leaves: [6, 7, 4, 9, 8]
    Node* root1 = new Node(3);
    root1->left = new Node(5, new Node(6), new Node(2, new Node(7), new Node(4)));
    root1->right = new Node(1, new Node(9), new Node(8));

    // Tree 2 Leaves: [6, 7, 4, 9, 8] (Different internal structure, same leaves)
    Node* root2 = new Node(3);
    root2->left = new Node(5, new Node(6), new Node(7));
    root2->right = new Node(1, new Node(4), new Node(2, new Node(9), new Node(8)));

    bool result1 = solution.leafSimilar(root1, root2);
    std::cout << "Test Case 1: " << (result1 ? "PASSED" : "FAILED")
               << " | Expected: True, Current: " << (result1 ? "True" : "False") << std::endl;

    // Clean up Test Case 1 memory
    deleteTree(root1);
    deleteTree(root2);

    // --- TEST CASE 2: Non-Leaf-Similar Trees ---
    // Tree 3 Leaves: [2, 3]
    Node* root3 = new Node(1, new Node(2), new Node(3));
    
    // Tree 4 Leaves: [3, 2]
    Node* root4 = new Node(1, new Node(3), new Node(2));

    bool result2 = solution.leafSimilar(root3, root4);
    std::cout << "Test Case 2: " << (!result2 ? "PASSED" : "FAILED")
               << " | Expected: False, Current: " << (result2 ? "True" : "False") << std::endl;

    // Clean up Test Case 2 memory
    deleteTree(root3);
    deleteTree(root4);

    return 0;
}