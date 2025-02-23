#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct Node{
    char data;
    vector<Node*> children;

    Node(char value) : data(value) {}
};


void display(Node* root){
    cout << root->data << " -> ";

    if ( !root -> children.empty()){
        cout <<  " -> ";
        for(Node* child : root->children){
            cout << child->data << " ";
        }

        for(Node* child : root->children){
            display(child);
        }
    }
}


int main(){
    Node* root = new Node('A');
    Node* node1 = new Node('B');
    Node* node2 = new Node('C');
    Node* node3 = new Node('D');
    Node* node4 = new Node('E');
    Node* node5 = new Node('F');
    Node* node6 = new Node('G');
    Node* node7 = new Node('H');
    Node* node8 = new Node('I');
    Node* node9 = new Node('J');
    Node* node10 = new Node('K');
    Node* node11 = new Node('L');
    Node* node12 = new Node('M');
    Node* node13 = new Node('N');
    Node* node14 = new Node('O');
    Node* node15 = new Node('P');
    Node* node16 = new Node('Q');
    Node* node17 = new Node('R');
    Node* node18 = new Node('S');
    Node* node19 = new Node('T');
    Node* node20 = new Node('U');
    Node* node21 = new Node('V');
    Node* node22 = new Node('W');
    Node* node23 = new Node('X');
    Node* node24 = new Node('Y');
    Node* node25 = new Node('Z');

    root->children.push_back(node1);
    root->children.push_back(node2);
    root->children.push_back(node3);
    root->children.push_back(node4);
    root->children.push_back(node5);
    root->children.push_back(node6);
    root->children.push_back(node7);
    root->children.push_back(node8);
    root->children.push_back(node9);
    root->children.push_back(node10);
    root->children.push_back(node11);
    root->children.push_back(node12);
    root->children.push_back(node13);
    root->children.push_back(node14);
    root->children.push_back(node15);
    root->children.push_back(node16);
    root->children.push_back(node17);
    root->children.push_back(node18);
    root->children.push_back(node19);
    root->children.push_back(node20);
    root->children.push_back(node21);
    root->children.push_back(node22);
    root->children.push_back(node23);
    root->children.push_back(node24);
    root->children.push_back(node25);
    display(root);
}

