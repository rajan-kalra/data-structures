#include <iostream>
#include <vector>
#include <queue>

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
    // Helper function to check if two subtrees are mirrors of each other
    bool isMirror(Node* t1, Node* t2) {
        // If both are null, they are symmetric
        if (t1 == nullptr && t2 == nullptr)
            return true;

        // If only one is null, they are asymmetric
        if (t1 == nullptr || t2 == nullptr)
            return false;
        
        // Check if current values match and subtrees are mirrored
        return (t1->val == t2->val)
            && isMirror(t1->left, t2->right)
            && isMirror(t1->right, t2->left);
    }

public:
    bool isSymmetric(Node* root) {
        if (root == nullptr)
            return true;
        return isMirror(root->left, root->right);
    }
};

// Helper function to build a tree from a level-order vector (using -1 or a flag for nulls)
// For simplicity, we use a special value (like -1) to represent null nodes in this test setup.
Node* buildTree(const std::vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    Node* root = new Node(nodes[0]);
    std::queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        Node* curr = q.front();
        q.pop();

        // Left child
        if (i < nodes.size() && nodes[i] != -1) {
            curr->left = new Node(nodes[i]);
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new Node(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// Helper function to clean up memory
void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete(root);
}

int main() {
    Solution solution;

    // Test Case 1: Symmetric Tree [1,2,2,3,4,4,3]
    //         1
    //        / \
    //       2   2
    //      / \ / \
    //     3  4 4  3
    std::vector<int> tree1 = {1, 2, 2, 3, 4, 4, 3};
    Node* root1 = buildTree(tree1);
    std::cout << "Test Case 1 (Symmetric): " 
              << (solution.isSymmetric(root1) ? "PASSED (True)" : "FAILED (False)") 
              << std::endl;

    // Test Case 2: Asymmetric Tree [1,2,2,-1,3,-1,3] (-1 represents null)
    //         1
    //        / \
    //       2   2
    //        \   \
    //         3   3
    std::vector<int> tree2 = {1, 2, 2, -1, 3, -1, 3};
    Node* root2 = buildTree(tree2);
    std::cout << "Test Case 2 (Asymmetric): " 
              << (!solution.isSymmetric(root2) ? "PASSED (False)" : "FAILED (True)") 
              << std::endl;

    // Test Case 3: Empty Tree []
    Node* root3 = nullptr;
    std::cout << "Test Case 3 (Empty Tree): " 
              << (solution.isSymmetric(root3) ? "PASSED (True)" : "FAILED (False)") 
              << std::endl;

    // Test Case 4: Single Node Tree [1]
    std::vector<int> tree4 = {1};
    Node* root4 = buildTree(tree4);
    std::cout << "Test Case 4 (Single Node): " 
              << (solution.isSymmetric(root4) ? "PASSED (True)" : "FAILED (False)") 
              << std::endl;

    // Clean up memory
    deleteTree(root1);
    deleteTree(root2);
    deleteTree(root4);

    return 0;
}