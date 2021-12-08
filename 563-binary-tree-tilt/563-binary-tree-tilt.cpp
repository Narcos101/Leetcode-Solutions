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
    int totalTilt = 0;
    int findTilt(TreeNode* root) {
        int sum = calc(root);
        return totalTilt;
    }
    
    int calc(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        int leftval = calc(root->left);
        int rightval = calc(root->right);
        totalTilt += abs(leftval-rightval);
        return root->val + leftval+rightval;
    }
};