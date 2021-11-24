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
    map<TreeNode *,int>mpp;
    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        if(mpp[root]) return mpp[root];
        int val = 0;
        if(root->left != NULL){
            val += rob(root->left->left) + rob(root->left->right);
        }
        if(root->right != NULL){
            val += rob(root->right->left) + rob(root->right->right);
        }
        val = max(val+root->val,rob(root->right)+rob(root->left));
        mpp[root] = val;
        return val;
    }
};