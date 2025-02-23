#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        right = left = nullptr;
    }
};

Node *insertNode(){
    int data;
    cout << "Enter the data of the node:";
    cin >> data;

    if (data == -1) return nullptr;

    Node* newNode = new Node(data);

    cout << "Enter the left child of " << data << endl;
    newNode->left = insertNode();

    cout << "Enter the right child of " << data << endl;
    newNode->right = insertNode();

    return newNode;
}
void preorder(Node* root){
    if(!root) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


int main(){
    cout << "creating a binary tree\n";
    Node* root = insertNode();
    preorder(root);
    return 0;
}