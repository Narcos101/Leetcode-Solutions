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
// if both left and right node are null then it is a leaf node 
//

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            return 1;
        }       
        int val = 0;
        if(root->left == NULL){
            return val = 1 + minDepth(root->right);
        }
        if(root->right == NULL){
            return val = 1 + minDepth(root->left);
        }
        return min(1 + minDepth(root->left), 1 + minDepth(root->right));
    }
};