#include <iostream>


using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node *insertNode(){
    int data;
    cout << "Enter the data of the node: ";
    cin >> data;

    if (data == -1) return nullptr; // -1 represent null


    Node* newNode = new Node(data);

    cout << "Enter the left child of " << data << ":\n"; // asking for left child
    newNode->left = insertNode(); // recursive call

    cout << "Enter the right child of " << data << ":\n";
    newNode->right = insertNode();

    return newNode;
}
    void inorder(Node* root){
        if(!root) return;

        inorder(root->left); // left
        cout << root->data << " "; // root
        inorder(root->right); // right
    }


int main(){
    cout << "creating a binary tree\n";
    Node* root = insertNode(); // root node
    inorder(root);
    return 0;
}

// Time complexity: O(n)
// Space complexity: O(n)
// Input: 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
// Output: 4 2 5 1 6 3 7 
//tree looks like:
//          1   
//         / \
//        2   3
//       / \ / \
//      4  5 6  7