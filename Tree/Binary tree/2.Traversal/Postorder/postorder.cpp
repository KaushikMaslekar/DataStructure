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

Node* insertNode(){
    int data;
    cout << "Enter the data of the node: ";
    cin >> data;

    if(data == -1) return nullptr;

    Node *newNode = new Node(data);

    cout << "Enter the left child of " << data << ":\n";
    newNode->left = insertNode();

    cout << "Enter the right child of " << data << ":\n";
    newNode->right = insertNode();

    return newNode;
}

void postorder(Node* root){
    if(!root) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){
    cout << "Creating a Binary Tree";
    Node* root = insertNode();
    postorder(root);
    return 0;
}