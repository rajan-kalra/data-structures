#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node (int k) {
            data = k;
            left = NULL;
            right = NULL;
        }
};

Node* createNode (int k) {
    Node *node = new Node(k);
    return node;
    }

void Preorder (Node *root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    Preorder (root->left);
    Preorder (root->right);
}

void LevelOrderLineByLine (Node *root) {
    if (root == NULL)
        return;

    int n = 0;
    queue<Node*> q;
    Node *current;
    q.push(root);

    while (q.empty() == false) {
        n = q.size ();
        /**
         * this while loop prints all elements
         * currently in queue & enques all the
         * elements of next level
         */
        while (n > 0) {
            current = q.front();
            q.pop();

            if (current->left)
                q.push(current->left);
            
            if (current->right)
                q.push(current->right);
                
            cout << current->data << " ";
            n--;
        }
        cout << "\n";
    }
}

int main() {
    Node *root = createNode (1);
    root->left = createNode (2);
    root->right = createNode (3);
    root->left->left = createNode (4);
    root->left->right = createNode (5);
    root->right->left = createNode (6);
    root->right->right = createNode (7);
    cout << "Level order line by line: \n";
    LevelOrderLineByLine (root);
    return 0;
}