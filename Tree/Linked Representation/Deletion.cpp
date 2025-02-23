#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    char data;
    TreeNode* leftmostChild;
    TreeNode* rightmostChild;   

    TreeNode(char val){
        data = val;
        leftmostChild = nullptr;
        rightmostChild = nullptr;
    }
};
void insert(TreeNode* parent, TreeNode* child){
    if(parent ->leftmostChild == nullptr){
        parent -> leftmostChild = child;
    } else {
        TreeNode* temp = parent ->leftmostChild;
        while(temp -> rightmostChild != nullptr){
            temp = temp -> rightmostChild;
        }
        temp -> rightmostChild = child;
    }
};

void display(TreeNode* root){
    if (root == nullptr) return;
    cout << root->data << ""   ;
    if (root -> leftmostChild != nullptr){
        cout << " ->";
        TreeNode* child = root ->leftmostChild;
        while ( child != nullptr){
            cout << child -> data << " ";
            child = child ->rightmostChild;
        }
    }

    TreeNode* child = root ->leftmostChild;
    while(child != nullptr){
        display(child);
        child = child->rightmostChild;
    }
};

void deletion(TreeNode* parent, char value){
    if(parent == nullptr) return;

    if (parent -> leftmostChild != nullptr && parent -> leftmostChild ->data == value){
        TreeNode* temp = parent -> leftmostChild;
        parent -> leftmostChild = temp -> rightmostChild;
        delete temp;
    }
    else{
        TreeNode* temp = parent -> leftmostChild;
        while (temp != nullptr && temp -> rightmostChild != nullptr){
            if ( temp -> rightmostChild -> data == value){
                TreeNode* toDelete = temp -> rightmostChild;
                temp -> rightmostChild = toDelete -> rightmostChild;
                delete toDelete;
                return;
            }
            temp = temp -> rightmostChild;
        }
    }
};


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
    cout << endl;

    deletion(root, '4');
    display(root);
    cout << endl;

    deletion(root, '2');
    display(root);
    cout << endl;

    return 0;
}