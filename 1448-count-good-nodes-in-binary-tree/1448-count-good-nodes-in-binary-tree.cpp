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
    int goodNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        queue<pair<TreeNode*,int>>q;
        q.push({root,root->val});
        int maxx = 1;
        int cnt = 0;
        while(!q.empty()){
            for(int i = 0; i < q.size(); i++){
                TreeNode *root = q.front().first;
                int prev = q.front().second;
                q.pop();
                if(root->val >= prev){
                    cnt++;
                }
                prev = max(prev,root->val);
                
                
                
                if(root->left != NULL){
                    q.push({root->left,prev});
                }
                if(root->right != NULL){
                    q.push({root->right,prev});
                }
            }
        }
        return cnt;
    }
    
    

};