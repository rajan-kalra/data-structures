#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Definition for a binary tree node as provided by LeetCode.
class Node {
    public:
        int val;
        Node* left;
        Node* right;
        
        Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    void binaryTreePaths(Node* root, string path, vector<string>& result) {
        if (root == nullptr)
            return;

        // Append current node's value to the path
        path += to_string(root->val);

        // If it's a leaf node, add the accumulated path to result
        if (root->left == nullptr && root->right == nullptr) {
            result.push_back(path);
            return;
        }

        // If not a leaf, add arrow and recurse down both branches
        path += "->";
        if (root->left)
            binaryTreePaths(root->left, path, result);
        if (root->right)
            binaryTreePaths(root->right, path, result);
    }

public:
    vector<string> binaryTreePaths(Node* root) {
        vector<string> result;
        if (root) {
            binaryTreePaths(root, "", result);
        }
        return result;
    }
};

// Helper function to free allocated tree nodes to prevent memory leaks
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

// Main function with test cases
int main() {
    Solution sol;

    // --- Test Case 1 ---
    //      1
    //    /   \
    //   2     3
    //    \
    //     5
    // Expected Output: ["1->2->5", "1->3"]
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->right = new Node(5);

    cout << "Test Case 1 Output:" << endl;
    vector<string> paths1 = sol.binaryTreePaths(root1);
    for (const string& path : paths1) {
        cout << "\"" << path << "\" ";
    }
    cout << "\n\n";

    // --- Test Case 2 ---
    // Single node tree: [1]
    // Expected Output: ["1"]
    Node* root2 = new Node(1);

    cout << "Test Case 2 Output:" << endl;
    vector<string> paths2 = sol.binaryTreePaths(root2);
    for (const string& path : paths2) {
        cout << "\"" << path << "\" ";
    }
    cout << "\n\n";

    // --- Clean Up ---
    freeTree(root1);
    freeTree(root2);

    return 0;
}