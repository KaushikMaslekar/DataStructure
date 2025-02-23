#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data = val;
        right = left = nullptr;
    }
};

int countNodes(Node* root){
    if (root == nullptr ) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
};

int main() {
    // Creating a simple binary tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(25);

    cout << "Total number of nodes in the tree: " << countNodes(root) << endl;

    return 0;
}