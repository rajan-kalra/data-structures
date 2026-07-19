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
public:
    bool isSameTree(Node* p, Node* q) {
        // If both nodes are null, the trees are identical up to this point
        if (p == nullptr && q == nullptr) {
            return true;
        }
        
        // If one is null and the other isn't, they aren't identical
        if (p == nullptr || q == nullptr) {
            return false;
        }
        
        // If the current node values don't match, they aren't identical
        if (p->val != q->val) {
            return false;
        }
        
        // Recursively check the left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Helper function to build a tree from a vector (BFS / LeetCode style)
// Using -1 to represent null nodes for simplicity in test cases
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

void runTestCase(int testNum, const std::vector<int>& tree1, const std::vector<int>& tree2, bool expected) {
    Node* p = buildTree(tree1);
    Node* q = buildTree(tree2);
    
    Solution solution;
    bool result = solution.isSameTree(p, q);
    
    std::cout << "Test Case " << testNum << ": " 
              << (result == expected ? "PASSED" : "FAILED") 
              << " (Expected: " << (expected ? "true" : "false") 
              << ", Got: " << (result ? "true" : "false") << ")\n";
              
    deleteTree(p);
    deleteTree(q);
}

int main() {
    // Note: -1 represents a null node in these test vectors
    
    // Test Case 1: Standard matching trees
    //     1          1
    //    / \        / \
    //   2   3      2   3
    runTestCase(1, {1, 2, 3}, {1, 2, 3}, true);

    // Test Case 2: Structurally different trees
    //     1          1
    //    /            \
    //   2              2
    runTestCase(2, {1, 2}, {1, -1, 2}, false);

    // Test Case 3: Same structure, different values
    //     1          1
    //    / \        / \
    //   2   1      1   2
    runTestCase(3, {1, 2, 1}, {1, 1, 2}, false);

    // Test Case 4: Both trees are completely empty
    runTestCase(4, {}, {}, true);

    // Test Case 5: One tree is empty, the other is not
    runTestCase(5, {}, {1}, false);

    return 0;
}