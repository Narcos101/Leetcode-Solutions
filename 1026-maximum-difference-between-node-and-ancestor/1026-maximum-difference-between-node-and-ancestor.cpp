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
    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        return max(max(calc(root,root->val), maxAncestorDiff(root->left)),maxAncestorDiff(root->right));
    }
    
    int calc(TreeNode *root,int val){
        if(root == NULL){
            return 0;
        }
        return max(max(abs(val-root->val),calc(root->left,val)),calc(root->right,val));
    }
    
};