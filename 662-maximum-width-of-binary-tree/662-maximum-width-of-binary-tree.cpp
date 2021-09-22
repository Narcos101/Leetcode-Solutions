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
    int widthOfBinaryTree(TreeNode* root) {
        // using level order traversal but in order to avoid overflow using 2*i+1 and 2*i+2 we use 1,2,3.... to name the            nodes and we can easily find the width of the node by subtracting the max index - min index.
        if(!root){
            return 0;
        }
        int ans = 0;
        queue<pair<TreeNode *, int>>q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            int minn = q.front().second;
            int first,last;
            for(int i = 0; i < size;i++){
                int curr_id = q.front().second-minn;
                TreeNode *node = q.front().first;
                if(i == 0) first = curr_id;
                if(i == size-1) last = curr_id;
                q.pop();
                if(node->left) q.push({node->left,2*curr_id+1});
                if(node->right) q.push({node->right,2*curr_id+2});
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};