/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        TreeNode *ans = NULL;
        calc(root,p->val,q->val,ans);
        return ans;
    }
    
    int calc(TreeNode *root, int p, int q,TreeNode*&ans){
        if(root == NULL){
            return false; 
        }
        int ans1 = 0;
        int left = calc(root->left,p,q,ans);
        int right = calc(root->right,p,q,ans);
        ans1 += left + right;
        if(root->val == p){
            ans1++;
        }
        if(root->val == q){
            ans1++;
        }
        if(ans1 == 2){
            ans = root;
            return 0;
        }
        return ans1;
    } 
};