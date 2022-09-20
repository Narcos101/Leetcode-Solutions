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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        // simple bfs and level order traversal
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            vector<TreeNode*>v;
            for(int i = 0; i < n;i++){
                TreeNode* rooot = q.front();
                q.pop();
                v.push_back(rooot);
                if(rooot->left != NULL){
                    q.push(rooot->left);
                }
                if(rooot->right != NULL){
                    q.push(rooot->right);
                }
            }
            int i =0;
            int j = n-1;
            if(level % 2){
                while(i <= j){
                    int temp = v[i]->val;
                    v[i]->val = v[j]->val;
                    v[j]->val = temp;
                    i++;
                    j--;
                }
            }
            level++;
        }
        return root;
    }
};