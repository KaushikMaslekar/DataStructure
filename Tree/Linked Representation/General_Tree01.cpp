#include <iostream>
#include <vector>

using namespace std;

struct TreeNode1{
    char data;
    TreeNode1 *leftmostChild;
    TreeNode1 *rightmostChild;

    TreeNode1(char val) : data(val), leftmostChild(NULL), rightmostChild(NULL) {}

};

void display(TreeNode1 *root){
    if(root == NULL) return;
    cout << root->data << " ";
    if(root->leftmostChild == NULL){
        cout << " ->";
        TreeNode1 *child = root->leftmostChild;
        while(child != NULL){
            cout << child->data << " ";
            child = child->rightmostChild;
        }
    }

    TreeNode1 *child = root->leftmostChild;
    while(child != NULL){
        display(child);
        child = child->rightmostChild;
    }
};

int main(){
    TreeNode1* root = new TreeNode1('A');
    TreeNode1* B = new TreeNode1('B');
    TreeNode1* C = new TreeNode1('C');
    TreeNode1* D = new TreeNode1('D');
    TreeNode1* E = new TreeNode1('E');
    TreeNode1* F = new TreeNode1('F');
    TreeNode1* G = new TreeNode1('G');
    TreeNode1* H = new TreeNode1('H');
    TreeNode1* I = new TreeNode1('I');
    TreeNode1* J = new TreeNode1('J');
    TreeNode1* K = new TreeNode1('K');
    TreeNode1* L = new TreeNode1('L');

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


    display(root);
    return 0;

}