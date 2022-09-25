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
    int rob(TreeNode* root) {
        unordered_map<TreeNode *,int>mpp;
        return calc(root,mpp);
    }
    
    
    int calc(TreeNode*root,unordered_map<TreeNode*,int>&mpp){
        if(root == NULL){
            return 0;
        }
        if(mpp.find(root) != mpp.end()){
            return mpp[root];
        }
        int left = 0;
        int right = 0;
        if(root->left != NULL){
            left = calc(root->left->left,mpp) + calc(root->left->right,mpp);
        }
        if(root->right != NULL){
            right = calc(root->right->left,mpp) + calc(root->right->right,mpp);
        }
        return mpp[root] = max(root->val + left + right,calc(root->left,mpp)+calc(root->right,mpp));
    }
    
};