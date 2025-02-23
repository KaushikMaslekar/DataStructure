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

    if (data = -1) return nullptr; // -1 represent null


    Node* newNode = new Node(data);

    cout << "Enter the left child of " << data << ":\n";
    newNode->left = insertNode();

    cout << "Enter the right child of " << data << ":\n";
    newNode->right = insertNode();

    return newNode;
}
    void inorder(Node* root){
        if(!root) return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }


int main(){
    cout << "creating a binary tree\n";
    Node* root = insertNode();
    inorder(root);
    return 0;
}

