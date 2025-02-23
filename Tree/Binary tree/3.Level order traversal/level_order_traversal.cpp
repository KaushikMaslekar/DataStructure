
#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node* left; 
    Node* right;

    Node(int val){ // constructor
        data = val; // data is the value of the node
        left = nullptr;
        right = nullptr;
    }
};

void levelOrder(Node* root){
    if (root == nullptr) return;

    queue<Node*> q; // queue to store the nodes
    q.push(root); // push the root node

    while (!q.empty()){ // while the queue is not empty
        Node* temp = q.front(); // get the front node
        q.pop(); // pop the front node

        cout << temp->data << " "; // print the data of the node
        

        //enqueue the left child
        if (temp->left != nullptr) q.push(temp->left);
        
        //enqueue the right child
        if (temp->right != nullptr) q.push(temp->right);
        }
}

int main(){
    // Node* root = new Node(1); // create a root node
    // Node* n1 = new Node(2); // create a left child
    // Node* n2 = new Node(3); // create a right child
    // Node* n3 = new Node(4); // create a left child of n1
    // Node* n5 = new Node(6); // create a right child of n1
    // Node* n6 = new Node(7); // create a right child of n2

    // root->left = n1; // set the left child of the root
    // root->right = n2; // set the right child of the root
    // n1->left = n3; // set the left child of n1
    // n1->right = n5; // set the right child of n1
    // n2->right = n6; // set the right child of n2

    Node* root = new Node(1); // create a root node
    root->left = new Node(2); // create a left child
    root->right = new Node(3); // create a right child
    root->left->left = new Node(4); // create a left child of n1
    root->left->right = new Node(5); // create a right child of n1
    root->right->left = new Node(6); // create a right child of n2
    root->right->right = new Node(7); // create a right child of n2

    cout << "Level order traversal: ";
    levelOrder(root); // print the level order traversal of the binary tree

    return 0;

}