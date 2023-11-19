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

Node* CreateNode (int k) {
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
    Node *root = CreateNode (1);
    root->left = CreateNode (2);
    root->right = CreateNode (3);
    root->left->left = CreateNode (4);
    root->left->right = CreateNode (5);
    root->right->left = CreateNode (6);
    root->right->right = CreateNode (7);
    cout << "Level order line by line: \n";
    LevelOrderLineByLine (root);
    return 0;
}