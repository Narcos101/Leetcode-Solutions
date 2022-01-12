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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
   /*       40 
          /    \
        20     60
       /  \    / \
      10  30  50 70
          / \
        25  NULL
    */
        if(root == NULL){
           TreeNode* mew = new TreeNode(val);
            return mew;
        }
        if(val < root->val){
            root->left = insertIntoBST(root->left,val);
        }
        else{
            root->right = insertIntoBST(root->right,val);
        }
        return root;
    }
};