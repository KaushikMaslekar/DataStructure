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
    if(parent ->leftmostChild == nullptr){//if parent has no child
        parent -> leftmostChild = child; //make child as leftmost child
    } else {
        TreeNode* temp = parent ->leftmostChild; // if parent has child
        while(temp -> rightmostChild != nullptr){ // go to the rightmost child of parent
            temp = temp -> rightmostChild; // go to the rightmost child of parent
        }
        temp -> rightmostChild = child; // 
    }
};

void deletion(TreeNode* parent, char value){
    if(parent == nullptr) return;

    if (parent -> leftmostChild != nullptr && parent -> leftmostChild ->data == value){ // if the leftmost child of parent is the value to be deleted
        TreeNode* temp = parent -> leftmostChild; // store the leftmost child of parent in temp
        parent -> leftmostChild = temp -> rightmostChild; // make the rightmost child of temp as the leftmost child of parent
        delete temp; // delete the temp node
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

// Output
// 1 ->2 3 4 5 6 7
// 1 ->2 3 5 6 7
// 1 ->3 5 6 7

// Time Complexity: O(n)
// Space Complexity: O(n)

//tree looks like before deletion
//         1
//        / \
//       2   3
//      / \  / \
//     4  5 6  7
//    / \
//   8  9

//tree looks like after deletion
//            1
//           / \
//          3   5
//         / \  / \
//        6  7
//       / \
//      8  9


