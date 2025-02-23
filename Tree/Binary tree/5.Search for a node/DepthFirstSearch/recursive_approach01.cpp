//using Structs

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data = val;
        right = nullptr;
        left  = nullptr;
    }
};

// Function to search for a key in the tree
bool search(Node* root, int key){ // returns true if the key is found, false otherwise
    if ( root == nullptr){ // if the tree is empty
        return false;
    }

    if ( root->data == key){ // if the key is found
        return true;
    }

    //bool left = search(root->left, key);
    //bool right = search(root->right, key);

    return search(root->left, key) || search(root->right, key);//left || right;
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    int key = 50;
    if (search(root, key)){
        cout << "Key found in the tree" << endl;
    }else{
        cout << "Key not found in the tree" << endl;
    }

    return 0;
}