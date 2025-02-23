#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) { 
        data = val;
        left = right = nullptr;
    }
};

int findHeight(Node* root){ //why int? because height is always an integer
    if (root == nullptr) return -1; // height of empty tree is -1


    queue<Node*> q;//queue to store the nodes of the tree
    q.push(root);
    int height = 0;//initialize height to 0

    // while ( !q.empty()){
    //     int size = q.size(); //size of the current level
    //     height++; //increment height for each level

    //     for (int i = 0; i < size; i++){ //traverse the current level
    //         Node* temp  = q.front(); //get the front element
    //         q.pop(); //pop the front element

    //     if (temp->left) //if left child
    //         q.push(temp->left); //push the left child
    //     if (temp->right) //if right child
    //         q.push(temp->right); //push the right child
    //     }
    // }

    
    while (!q.empty()){
        int size = q.size(); //size of the current level
        height++; //increment height for each level

        while (size--){ //traverse the current level //size-- is equivalent to for loop
            Node* temp  = q.front(); //get the front element
            q.pop(); //pop the front element
        if (temp->left) //if left child
            q.push(temp->left); //push the left child
        if (temp->right) //if right child
            q.push(temp->right); //push the right child
        }
    }
    return height; // return the height of the tree
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    cout << findHeight(root) << endl; //2
    return 0;
}
//output : 2
// Time Complexity: O(n), where n is the number of nodes in the binary tree.