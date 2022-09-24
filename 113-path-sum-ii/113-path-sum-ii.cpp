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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        if(root == NULL){
            return ans;
        }
        vector<int>v;
        calc(root,targetSum,ans,v);
        return ans;
    }
    
    void calc(TreeNode* root,int ts,vector<vector<int>>&ans,vector<int>v){
        if(root == NULL){
            return;
        }
        v.push_back(root->val);
        if(root->left == NULL && root->right == NULL && ts-root->val == 0){
            ans.push_back(v);
            return;
        }
        calc(root->left,ts-(root->val),ans,v);
        calc(root->right,ts-(root->val),ans,v);
    }
};