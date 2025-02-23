#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    char data;
    TreeNode* leftmostChild;
    TreeNode* rightmostChild;

    TreeNode(char val) : data(val), leftmostChild(NULL), rightmostChild(NULL) {} 

};

void display(TreeNode* root){
    if (root == NULL) return;
    cout << root->data << " ";
    if (root->leftmostChild == NULL) {
    cout << " - >";
    TreeNode* child = root->leftmostChild;
    while(child!=NULL){
        cout << child->data << " ";
        child = child->rightmostChild;
    }
    }

    TreeNode* child = root->leftmostChild;
    while(child!=NULL){
        display(child);
        child = child->rightmostChild;
    }
};

void insert(TreeNode* parent, TreeNode* child){
    if(parent -> leftmostChild == NULL){
        parent ->leftmostChild = child;
    }else{
        TreeNode* temp = parent ->leftmostChild;
        while(temp ->rightmostChild != NULL){
            temp = temp ->rightmostChild;
        }
        temp ->rightmostChild = child;
    }
};

int main(){
    TreeNode* root = new TreeNode('A');
    TreeNode* B = new TreeNode('B');
    TreeNode* C = new TreeNode('C');
    TreeNode* D = new TreeNode('D');
    TreeNode* E = new TreeNode('E');
    TreeNode* F = new TreeNode('F');
    TreeNode* G = new TreeNode('G');
    TreeNode* H = new TreeNode('H');
    TreeNode* I = new TreeNode('I');
    TreeNode* J = new TreeNode('J');
    TreeNode* K = new TreeNode('K');
    TreeNode* L = new TreeNode('L');
    TreeNode* M = new TreeNode('M');
    TreeNode* N = new TreeNode('N');
    TreeNode* O = new TreeNode('O');
    TreeNode* P = new TreeNode('P');
    TreeNode* Q = new TreeNode('Q');
    TreeNode* R = new TreeNode('R');
    TreeNode* S = new TreeNode('S');
    TreeNode* T = new TreeNode('T');
    TreeNode* U = new TreeNode('U');
    TreeNode* V = new TreeNode('V');
    TreeNode* W = new TreeNode('W');
    TreeNode* X = new TreeNode('X');
    TreeNode* Y = new TreeNode('Y');

    insert(root, B);
    insert(root, C);
    insert(B, D);
    insert(B, E);
    insert(B, F);
    insert(C, G);
    insert(C, H);
    insert(C, I);
    insert(D, J);
    insert(D, K);
    insert(E, L);
    insert(E, M);
    insert(F, N);
    insert(F, O);
    insert(G, P);
    insert(G, Q);
    insert(H, R);
    insert(H, S);
    insert(I, T);
    insert(I, U);
    insert(J, V);
    insert(J, W);
    insert(K, X);
    insert(K, Y);

    display(root);
    return 0;
}


// Output: A B D J K X Y E L M F N O C G P Q H R S I T U
// Time Complexity: O(n)
// Space Complexity: O(n)
// n = number of nodes in the tree
//How tree look like:
//          A
//         / \
//        B   C
//       /|   |\
//      D E   F G
//     /| |   | |\
//    J K L   N O P Q
//     /|       | |
//    X Y       R S
//              |
//              T
//              |
//              U
//              |
//              V
//              |
//              W
//              |
//              X
//              |
//              Y


