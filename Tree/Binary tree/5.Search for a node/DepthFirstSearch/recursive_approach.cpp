//using class 

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

// Recursive approach

bool search(Node* root, int key){
    if(root == nullptr) // if tree is empty
        return false;
    
    if(root->data == key) // if key is found
        return true;

    return search(root->left, key) || search(root->right, key); // search in left and right subtree

};

int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    int key = 50;

    if(search(root, key))
        cout << "Key found";
    else
        cout << "Key not found";

    return 0;
}

/*Recursive Approach (DFS)

Uses preorder traversal to search.
Recursively checks left and right subtrees.
Time Complexity: O(N)
Space Complexity: O(H) (height of the tree).*/