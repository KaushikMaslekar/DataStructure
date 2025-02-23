#include <iostream>
using namespace std;

// Structure for a Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Function to find the minimum node in a subtree (inorder successor)
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to delete a node in a binary tree
Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    // If key is smaller, move left
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    
    // If key is greater, move right
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    
    // If the key is found
    else {
        // Case 1: No child (leaf node)
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children (find inorder successor)
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data; // Copy successor data
            root->right = deleteNode(root->right, temp->data); // Delete successor
        }
    }
    return root;
}

// Function to perform inorder traversal
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Driver code
int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << endl;

    int key = 50;
    root = deleteNode(root, key);

    cout << "Inorder traversal after deleting " << key << ": ";
    inorder(root);
    cout << endl;

    return 0;
}

/*
Output:
Inorder traversal before deletion: 20 30 40 50 60 70 80
Inorder traversal after deleting 50: 20 30 40 60 70 80

tree looks like:
        50
       /  \
      30   70
     / \   / \
    20 40 60 80

After deleting 50, tree looks like:
        60
       /  \
      30   70
     / \     \

*/
