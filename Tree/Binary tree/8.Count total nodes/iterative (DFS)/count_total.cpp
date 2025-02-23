#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Iterative function to count nodes (BFS Level Order)
int countNodesIterative(Node* root) {
    if (!root) return 0;

    queue<Node*> q;
    q.push(root);
    int count = 0;

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        count++;

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    return count;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(25);

    cout << "Total number of nodes (Iterative): " << countNodesIterative(root) << endl;

    return 0;
}
