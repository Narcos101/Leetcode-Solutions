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
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int>q;
        calc(q,root,k);
        return q.top();
    }
    
    void calc(priority_queue<int>&q, TreeNode *root, int k){
        if(root == NULL){
            return;
        }
        q.push(root->val);
        if(q.size() > k){
            q.pop();
        }
        calc(q,root->left,k);
        calc(q,root->right,k);
    }
    
};