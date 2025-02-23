//we use recursive approach to find the height of the tree

#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int findHeight(Node* root){ // we are finding the height of the tree
    if( root == nullptr){ // if the tree is empty
        return -1; // height of the tree is -1
    }

    int leftHeight = findHeight(root->left); // finding the height of the left subtree
    int rightHeight = findHeight(root->right); // finding the height of the right subtree

    return max(leftHeight, rightHeight) + 1; // returning the maximum height of the left and right subtree //+ 1 is added to include the root node


}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Height of the tree: " << findHeight(root) << endl;

    return 0;
}

//output : Height of the tree: 2
// (For a tree with 3 levels, height is 2 because it counts edges.)
// Time complexity: O(n) where n is the number of nodes in the tree.