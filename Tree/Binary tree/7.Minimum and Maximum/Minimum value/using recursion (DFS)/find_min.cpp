// Traverse tree using DFS
#include <iostream>
#include <climits> //For INT_MIN and INT_MAX

using namespace std;

/*
Purpose: Focuses solely on finding the minimum value in a binary tree using Depth-First Search (DFS).
Tree Construction: The tree is manually created by explicitly assigning child nodes.
Functionality:
Defines a Node structure.
Implements findMin() using DFS.
Constructs a sample binary tree.
Finds and prints the minimum value.

*/
//if you want to find the minimum value then go for this steps

struct Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int val){
        data = val;
        right = left = nullptr;
    }
};


int findMin(Node* root){
    if ( root == nullptr) return INT_MAX; //return max possible value if tree is empty
        return min(root->data, min(findMin(root->left), findMin(root->right)));
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(25);

    cout << "minimum value" << findMin(root) << endl;

}