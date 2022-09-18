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
    int minCameraCover(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int sum = 0;
        if(dfs(root,sum) == 0){
            sum++;
        }
        // 0 - when the root is not monitored and needs a guy for getting it monitored
        // 1 - when the root is being monitored but it doesn't have a camera 
        // 2 - when the root is being monitored and it has a camera
        return sum;
    }
    
    int dfs(TreeNode*root,int&sum){
        if(root == NULL){
            return 1;
        }
        int l = dfs(root->left,sum);
        int r = dfs(root->right,sum);
        if(l == 0 || r == 0){
            sum++;
            return 2;
        }
        else if(l == 2 || r == 2){
            return 1;
        }
        else{
            return 0;
        }
        return -1;
    }
    
    
    
};