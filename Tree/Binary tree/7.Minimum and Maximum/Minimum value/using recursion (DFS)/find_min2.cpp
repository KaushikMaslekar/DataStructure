#include <iostream>
#include <queue>
#include <climits>
using namespace std;

/*
Insert function to create a tree
Different traversal methods to display the tree
Find Min function
*/

/*
Purpose: Implements a full-fledged Binary Search Tree (BST) with insertion and multiple traversal methods.
Tree Construction: Uses an insert() function to dynamically build the tree.
Functionality:
Defines a Node structure.
Implements insert() function to add nodes based on BST properties.
Provides four tree traversal methods:
Inorder (DFS)
Preorder (DFS)
Postorder (DFS)
Level-order (BFS)
Implements findMin() to find the minimum value.
Constructs a tree dynamically and performs different operations.
*/

//If you want a complete BST implementation with traversals 
struct Node{
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data = val;
        right = left = nullptr;
    }
};

Node* insert(Node* root, int val){
    if (!root ) return new Node(val); 

    if (val < root->data){
        root -> left = insert(root->left, val);
    }
    if ( val > root->data){
        root -> right = insert(root->right, val);
    }
    return root;
}

// 1️⃣ Inorder Traversal (Left -> Root -> Right)

void inorder(Node* root){
    if (!root) return;

    inorder(root -> left);
    cout << root->data << "->";
    inorder(root -> right);

}

// 2️⃣ Preorder Traversal (Root -> Left -> Right)

void preorder(Node* root){
    if (!root) return;
    cout << root -> data << " ->";
    preorder(root->left);
    preorder(root->right);
}

// 3️⃣ Postorder Traversal (Left -> Right -> Root)

void postorder(Node* root){
    if (!root) return;
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << "->";
}

// 4️⃣ Level Order Traversal (BFS)

void levelOrder(Node* root){
    if (!root ) return;

    queue<Node*> q; //queue to store the nodes
    q.push(root); // push the root node

    while (!q.empty()){ //while queue is not null
        Node* temp = q.front(); //get the front node 
        q.pop(); //pop the front node

        //print the data
        cout << temp->data << " ->";
        
        //enqueue the left child
        if (temp->left) q.push(temp->left);
        
        //enqueue the right child
        if(temp->right) q.push(temp->right);
    }
}

// Function to find the minimum value in a binary tree

int findMin(Node* root) {
    if (!root) return INT_MAX;
    return min(root->data, min(findMin(root->left), findMin(root->right)));
}

int main(){
    Node* root = new Node(10); // create a root node
    root->left = new Node(5); // create a left child
    root->right = new Node(20); // create a right child
    root->left->left = new Node(3); // create a left child of n1
    root->left->right = new Node(7); // create a right child of n1
    root->right->left = new Node(25); // create a right child of n2
    root->right->right = new Node(50); // create a right child of n2

    cout << "Inorder traversal = ";
    inorder(root);
    cout << endl;

    cout << "Preorder traversal =";
    preorder(root);
    cout << endl;

    cout << "Postorder traversal =";
    postorder(root);
    cout << endl;

    cout << "Level order traversal =";
    levelOrder(root);
    cout << endl;

    cout << "Minimum element is = " << findMin(root);
    return 0;
}