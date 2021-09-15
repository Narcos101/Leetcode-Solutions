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
        vector<int> postorderTraversal(TreeNode* root) {
            // using 2 stacks;
            // first one to process the nodes, Second one to push the values in the                 vector and then print them from top to bottom
            stack<TreeNode *>st1;stack<TreeNode *>st2;
            vector<int>ans;
            st1.push(root);
            if(root == NULL) return ans;
            while(!st1.empty()){
                root = st1.top();
                st1.pop();
                st2.push(root);
                if(root->left != NULL){
                    st1.push(root->left);
                }
                if(root->right != NULL){
                    st1.push(root->right);
                }
            }
            while(!st2.empty()){
                root = st2.top();
                st2.pop();
                ans.push_back(root->val);
            }
            return ans;
            
        }
};