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
    bool hasPathSum(TreeNode* root, int ts) {
        if(root == NULL){
            return false;
        }
        return calc(root,0,ts);
        
    }
    
    
    bool calc(TreeNode* root,int val,int ts){
        if(root == NULL){
            return false;
        }
        if(root->left == NULL && root->right == NULL){
            if(val+root->val == ts){
                return true;
            }
            return false;
        }
        return calc(root->left,val + root->val,ts) || calc(root->right,val + root->val,ts);
    }
};