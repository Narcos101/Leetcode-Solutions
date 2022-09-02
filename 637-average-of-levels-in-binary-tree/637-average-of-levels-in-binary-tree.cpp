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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            double sum = 0;
            for(int i = 0; i < n;i++){
                TreeNode *nroot = q.front();
                int topval = q.front()->val;
                q.pop();
                sum += topval;
                if(nroot->left != NULL){
                    q.push(nroot->left);
                }
                if(nroot->right != NULL){
                    q.push(nroot->right);
                }
            }
            ans.push_back(sum/n);
        }
        return ans;
    }
};