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
    unordered_map<int,int>mpp;
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL){
            return false;
        }        
        // perform a inorder traversal to find a pair
        return calc(root,k);
    }
    
    bool calc(TreeNode *root, int k){
        if(root == NULL){
            return false;
        }
        if(mpp[k-root->val] != 0){
            return true;
        }
        else{
            mpp[root->val]++;
            return calc(root->left,k) || calc(root->right,k);
        }
    }
    
    
    
    
};