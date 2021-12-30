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
        if(q->val < p->val){
            swap(p,q);
        }
        return calc(root,p,q);
        
    }
    
    TreeNode* calc(TreeNode* root,TreeNode *p, TreeNode *q){
        if(root == NULL){
            return NULL;
        }
        TreeNode* node;
        if(root->val < q->val && root->val > p->val){
            node = root;
        }
        else if(q->val < root->val){
            node = calc(root->left,p,q);
        }
        else if(p->val > root->val){
            node = calc(root->right,p,q);
        }
        return node;
    }
};