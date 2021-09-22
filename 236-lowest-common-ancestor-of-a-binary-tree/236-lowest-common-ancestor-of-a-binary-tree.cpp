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
        // Brute force solution would to be find the path from root to the node and store it for both the nodes.
        // Then traverse through both the arrays and find the common path between them TC- O(n) && SC-O(n);
        // a proper solution would be to find the two nodes while traversing together
        
        
        
        if(root == NULL || root->val == p->val || root->val == q->val){
            return root;
        }
        
        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);
        
        if(left == NULL){
            return right;
        }
        else if(right == NULL){
            return left;
        }
        else{
            return root;
        }
        
    }
};