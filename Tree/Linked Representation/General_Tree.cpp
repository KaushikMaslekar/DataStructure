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
    TreeNode* child = root->leftmostChild; // leftmostChild is a pointer to the first child of the node
    while(child!=NULL){ // while there are children
        cout << child->data << " "; // print the data of the child
        child = child->rightmostChild; // move to the next child
    }
    }

    TreeNode* child = root->leftmostChild; // leftmostChild is a pointer to the first child of the node
    while(child!=NULL){ // while there are children
        display(child); // print the data of the child
        child = child->rightmostChild; // move to the next child
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
    TreeNode* Z = new TreeNode('Z');

    root->leftmostChild = B;
    B->rightmostChild = C;
    C->rightmostChild = D;
    D->rightmostChild = E;
    E->rightmostChild = F;
    F->rightmostChild = G;
    G->rightmostChild = H;
    H->rightmostChild = I;
    I->rightmostChild = J;
    J->rightmostChild = K;
    K->rightmostChild = L;
    L->rightmostChild = M;
    M->rightmostChild = N;
    N->rightmostChild = O;
    O->rightmostChild = P;
    P->rightmostChild = Q;
    Q->rightmostChild = R;
    R->rightmostChild = S;
    S->rightmostChild = T;
    T->rightmostChild = U;
    U->rightmostChild = V;
    V->rightmostChild = W;
    W->rightmostChild = X;
    X->rightmostChild = Y;
    Y->rightmostChild = Z;

    display(root);
    return 0;
}