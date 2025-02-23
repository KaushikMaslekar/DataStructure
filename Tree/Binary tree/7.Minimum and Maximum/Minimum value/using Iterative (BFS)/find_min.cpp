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

// Function to find min and max using BFS
void findMin(Node* root, int &minValue) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    minValue = root->data;

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        minValue = min(minValue, temp->data);

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}

// Driver code
int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(25);

    int minValue;
    findMin(root, minValue);

    cout << "Minimum value: " << minValue << endl;

    return 0;
}
