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
    
    bool calc(TreeNode *root,long long minn,long long maxx){
        if(root == NULL){
            return true;
        }
        if(root->val > minn && root->val < maxx){
            return calc(root->left,minn,root->val) && calc(root->right,root->val,maxx);
        } 
        else{
            return false;
        }
    }
    
    
    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return calc(root,LONG_MIN,LONG_MAX);
    }
};