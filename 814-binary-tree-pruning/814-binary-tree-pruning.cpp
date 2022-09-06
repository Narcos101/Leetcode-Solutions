/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        return calc(root) ? NULL : root;
    }
    
    bool calc(TreeNode *root){
        if(root == NULL){
            return true;
        }
        int flag = 0;
        if(root->val == 0){
            flag = 1;
        }
        bool flag1 = calc(root->left);
        if(flag1 == true){
            root->left = NULL;
        }
        bool flag2 = calc(root->right);
        if(flag2 == true){
            root->right = NULL;
        }
        return flag && flag1 && flag2;
    }
     
};