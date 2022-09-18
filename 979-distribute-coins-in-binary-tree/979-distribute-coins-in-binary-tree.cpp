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
    int distributeCoins(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int moves = 0;
        calc(root,moves);
        return moves;
    }
    
    int calc(TreeNode*root, int&ans){
        if(root == NULL){
            return 0;
        }
        int l = calc(root->left,ans);
        int r = calc(root->right,ans);
        ans += abs(l) + abs(r);
        return root->val + l + r - 1;
    }
};