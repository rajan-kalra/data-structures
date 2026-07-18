#include <iostream>
#include <stack>
using namespace std;

class Node {
    public:
        int data;
        Node *left, *right;

        Node () {
            data = 0;
            left = NULL;
            right = NULL;
        }
};

void printSpiral( Node* root) {
    if (root == NULL)
        return;

    stack<Node*> s1;
    stack<Node*> s2;

    s1.push(root);

    while (s1.empty() == false || s2.empty() == false) {
        // Print nodes of current level from s1 and push nodes of
        // next level to s2
        while (s1.empty() == false) {
            Node* temp = s1.top();
            s1.pop();
            cout << temp->data << " ";

            // Note that is right is pushed before left
            if (temp->right)
                s2.push(temp->right);
            if (temp->left)
                s2.push(temp->left);
        }

        // Print nodes of current level from s2 and push nodes of
        // next level to s1
        while (s2.empty() == false) {
            Node* temp = s2.top();
            s2.pop();
            cout << temp->data << " ";

            // Note that is left is pushed before right
            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }
    }
}

struct Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    return (node);
}

int main() {
    // Test 1: balanced tree
    //           1
    //         /   \
    //        2     3
    //       / \   / \
    //      7   6 5   4
    // Expected: 1 2 3 4 5 6 7
    struct Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(7);
    root1->left->right = newNode(6);
    root1->right->left = newNode(5);
    root1->right->right = newNode(4);
    cout << "Test 1 (balanced tree): " << endl;
    cout << "  Expected: 1 2 3 4 5 6 7" << endl;
    cout << "  Actual:   ";
    printSpiral(root1);
    cout << endl;

    // Test 2: empty tree
    // Expected: (nothing printed)
    cout << "Test 2 (empty tree): " << endl;
    cout << "  Expected:  (nothing printed)" << endl;
    cout << "  Actual:   ";
    printSpiral(NULL);
    cout << endl;

    // Test 3: single node
    // Expected: 1
    struct Node* root3 = newNode(1);
    cout << "Test 3 (single node): " << endl;
    cout << "  Expected: 1" << endl;
    cout << "  Actual:   ";
    printSpiral(root3);
    cout << endl;

    // Test 4: left-skewed tree
    //       1
    //      /
    //     2
    //    /
    //   3
    //  /
    // 4
    // Expected: 1 2 3 4
    struct Node* root4 = newNode(1);
    root4->left = newNode(2);
    root4->left->left = newNode(3);
    root4->left->left->left = newNode(4);
    cout << "Test 4 (left-skewed tree): " << endl;
    cout << "  Expected: 1 2 3 4" << endl;
    cout << "  Actual:   ";
    printSpiral(root4);
    cout << endl;

    // Test 5: right-skewed tree
    // Expected: 1 2 3 4
    struct Node* root5 = newNode(1);
    root5->right = newNode(2);
    root5->right->right = newNode(3);
    root5->right->right->right = newNode(4);
    cout << "Test 5 (right-skewed tree): " << endl;
    cout << "  Expected: 1 2 3 4" << endl;
    cout << "  Actual:   ";
    printSpiral(root5);
    cout << endl;

    return 0;
}