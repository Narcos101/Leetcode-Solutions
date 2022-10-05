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
    int amountOfTime(TreeNode* root, int start) {
        if(root == NULL){
            return 0;
        }
        unordered_map<TreeNode*,TreeNode*>mpp;
        calc(root,mpp);
        unordered_map<TreeNode*,int>vis;
        queue<TreeNode*>q;
        if(root->val == start){
            q.push(root);
            vis[root]++;
        }
        else{
            for(auto i : mpp){
                if(i.first->val == start){
                    vis[i.first]++;
                    q.push(i.first);
                    break;
                }
            }
        }
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n;i++){
                TreeNode*top = q.front();
                q.pop();
                if(mpp.find(top)!=mpp.end() && !vis[mpp[top]]){
                    q.push(mpp[top]);
                    vis[mpp[top]]++;
                }
                if(top->left != NULL && !vis[top->left]){
                    q.push(top->left);
                    vis[top->left]++;
                }
                if(top->right != NULL && !vis[top->right]){
                    q.push(top->right);
                    vis[top->right]++;
                } 
            }
            level++;
        }
        return level-1;
    }
    
    
    void calc(TreeNode *root,unordered_map<TreeNode*,TreeNode*>&mpp){
        if(root == NULL){
            return;
        }
        if(root->left != NULL){
            mpp[root->left] = root;
            calc(root->left,mpp);
        }
        if(root->right != NULL){
            mpp[root->right] = root;
            calc(root->right,mpp);
        }
    }
};