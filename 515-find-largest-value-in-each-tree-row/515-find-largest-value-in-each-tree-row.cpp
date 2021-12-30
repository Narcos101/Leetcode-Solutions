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
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode *>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty()){
            int maxx = INT_MIN;
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode *root = q.front();
                maxx = max(maxx,root->val);
                q.pop();
                if(root->left != NULL){
                    q.push(root->left);
                }
                if(root->right != NULL){
                    q.push(root->right);
                }
            }
            ans.push_back(maxx);
        }
        return ans;
    }
};