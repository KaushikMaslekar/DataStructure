// Traverse tree using DFS
#include <iostream> 
#include <climits>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int val){
        data = val;
        right = left = nullptr;
    }
};

int findMax(Node* root){
    if ( root == nullptr) return INT_MIN; //return min possible value if tree is empty
        return max(root->data, max(findMax(root->left), findMax(root->right)));
}

int main(){
    Node* root = new Node(10);
    root ->left = new Node(5);
    root -> right = new Node(20);
    root -> left -> left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(25);

    cout << "maximum value" << findMax(root);
}
