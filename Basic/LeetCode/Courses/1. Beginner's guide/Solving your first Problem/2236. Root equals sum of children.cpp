#include <iostream>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 bool checkTree(TreeNode* root){
    int referal = root -> val;
    int left = root -> left -> val;
    int right = root -> right -> val;
    return referal == left + right;
 }

int main(){
    TreeNode* tree = new TreeNode(0, new TreeNode(5), new TreeNode(-5));
    cout << checkTree(tree);
    return 0;
}