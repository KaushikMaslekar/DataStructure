//BFS - level order traversal

#include <iostream>
#include <queue>

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

bool search(Node* root, int key){
    if ( root == nullptr){
        return false;
    }

    queue<Node*> q; //create a queue
    q.push(root);//push the root node

    while (!q.empty()){
        Node* temp = q.front(); //get the front element
        q.pop(); //pop the front element

        if ( temp -> data == key){
            return true;
        }

        if (temp -> left){ //if left child exists
            q.push(temp -> left); //push the left child
        }
        if (temp -> right){ //if right child exists
            q.push(temp -> right); //push the right child
    }
    return false;    
}
}; 

int main(){
    Node* root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> left -> left = new Node(40);
    root -> left -> right = new Node(50);
    root -> right -> left = new Node(60);
    root -> right -> right = new Node(70);


    int key = 35;
    if(search(root, key)){
        cout << "Key found";
    }
    else{
        cout << "Key not found";
    }
}

/*
    Iterative Approach (BFS)

    Uses Level Order Traversal.
    Uses a queue to store nodes.
    Time Complexity: O(N)
    Space Complexity: O(N) (for queue storage).

*/