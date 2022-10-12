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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        if(n % 2 == 0){
            return ans;
        }
        return calc(n);
    }
    
    
    vector<TreeNode*> calc(int n){
        vector<TreeNode*>v;
        if(n == 1){
            v.push_back(new TreeNode(0,NULL,NULL));
            return v;
        }
        for(int i = 1; i < n;i+=2){
            auto left = calc(i);
            auto right = calc(n-i-1);
            for(auto l : left){
                for(auto r: right){
                    v.push_back(new TreeNode(0,l,r));
                }
            }
        }
        return v;
    }
    
    
    
};