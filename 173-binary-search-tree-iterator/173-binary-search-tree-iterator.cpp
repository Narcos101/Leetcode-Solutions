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
class BSTIterator {
public:
    vector<int>nodes;
    int i,n;
    BSTIterator(TreeNode* root) {
        i = 0;
        inorder(root,nodes);
        n = nodes.size();
    }
    
    int next() {
        int nodeval = nodes[i++];
        return nodeval;
    }
    
    bool hasNext() {
        if(i != n){
            return true;
        }
        return false;
    }
    void inorder(TreeNode*root,vector<int>&nodes){
        if(root == NULL){
            return;
        }
        inorder(root->left,nodes);
        nodes.push_back(root->val);
        inorder(root->right,nodes);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */