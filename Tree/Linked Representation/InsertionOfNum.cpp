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
    cout << root->data << ""   ;
    if (root -> leftmostChild != NULL){
        cout << " ->";
        TreeNode* child = root ->leftmostChild;
        while ( child != NULL){
            cout << child -> data << " ";
            child = child ->rightmostChild;
        }
    }

    TreeNode* child = root ->leftmostChild;
    while(child != NULL){
        display(child);
        child = child->rightmostChild;
    }
};

void insert(TreeNode* parent, TreeNode* child){
    if(parent ->leftmostChild == NULL){
        parent -> leftmostChild = child;
    } else {
        TreeNode* temp = parent ->leftmostChild;
        while(temp -> rightmostChild != NULL){
            temp = temp -> rightmostChild;
        }
        temp -> rightmostChild = child;
    }
}

int main(){
    TreeNode* root = new TreeNode('1');
    TreeNode* two = new TreeNode('2');
    TreeNode* three = new TreeNode('3');
    TreeNode* four = new TreeNode('4');
    TreeNode* five = new TreeNode('5');
    TreeNode* six = new TreeNode('6');
    TreeNode* seven = new TreeNode('7');
    TreeNode* eight = new TreeNode('8');
    TreeNode* nine = new TreeNode('9');

    

    insert(root, two);
    insert(root, three);
    insert(two, four);
    insert(two, five);
    insert(three, six);
    insert(three, seven);
    insert(four, eight);
    insert(four, nine);



    display(root);
    return 0;
}

// Output: 1 ->2 4 5 ->3 6 7 ->4 8 9 ->5 ->6 ->7 ->8 ->9
//tree looks like this
//          1
//         / \
//        2   3
//       / \  / \
//      4   5 6  7
//     / \
//    8   9