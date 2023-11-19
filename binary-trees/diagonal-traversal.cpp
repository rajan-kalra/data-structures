#include <iostream>
#include <map>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node () {
            data = 0;
            left = NULL;
            right = NULL;
        }
};

void diagonalPrintUtil(Node* root, int verticalDistance, map<int, vector<int>> &diagonalPrint) {
    if (root == NULL)
        return;

    diagonalPrint[verticalDistance].push_back(root->data);

    // increment the vertical distance if left child
    diagonalPrintUtil(root->left, verticalDistance + 1, diagonalPrint);

    // vertical distance remains same for right child
    diagonalPrintUtil(root->right, verticalDistance, diagonalPrint);
}

void diagonalPrint(Node* root) {
    map<int, vector<int> > diagonalPrint;
    diagonalPrintUtil(root, 0, diagonalPrint);

    cout << "Diagonal Traversal of binary tree : \n";
    for (auto it : diagonalPrint) {
        vector<int> elementsVector = it.second;
        for (auto element : elementsVector)
            cout << element << " ";
        cout << endl;
    }
}

Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main() {
    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);

    diagonalPrint(root);

    return 0;
}
