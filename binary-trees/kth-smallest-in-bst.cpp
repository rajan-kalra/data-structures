#include <iostream>
#include <vector>
#include <stack>

// Definition for a binary tree node.
class Node {
    public:
        int val;
        Node *left;
        Node *right;
        Node() : val(0), left(nullptr), right(nullptr) {}
        Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Iterative In-Order Traversal (O(H + k) time, O(H) space)
    int kthSmallest(Node* root, int k) {
        std::stack<Node*> st;
        Node* curr = root;

        while (curr != nullptr || st.empty() == false) {
            // Traverse to the leftmost node
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            // Process the current node
            curr = st.top();
            st.pop();
            
            k--;
            if (k == 0) {
                return curr->val;
            }

            // Move to the right subtree
            curr = curr->right;
        }

        return -1; // Fallback for invalid k
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
    Solution sol;

    // --- Test Case 1 ---
    // Tree: [3, 1, 4, null, 2], k = 1
    //       3
    //      / \
    //     1   4
    //      \
    //       2
    Node* root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(4);
    root1->left->right = new Node(2);

    int k1 = 1;
    std::cout << "Test 1 - Expected: 1, Got: " << sol.kthSmallest(root1, k1) << std::endl;

    // --- Test Case 2 ---
    // Tree: [5, 3, 6, 2, 4, null, null, 1], k = 3
    //         5
    //        / \
    //       3   6
    //      / \
    //     2   4
    //    /
    //   1
    Node* root2 = new Node(5);
    root2->left = new Node(3);
    root2->right = new Node(6);
    root2->left->left = new Node(2);
    root2->left->right = new Node(4);
    root2->left->left->left = new Node(1);

    int k2 = 3;
    std::cout << "Test 2 - Expected: 3, Got: " << sol.kthSmallest(root2, k2) << std::endl;

    // Cleanup memory
    deleteTree(root1);
    deleteTree(root2);

    return 0;
}