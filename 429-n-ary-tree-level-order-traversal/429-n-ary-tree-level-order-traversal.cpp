/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(root == NULL) return ans;
        queue<Node*>q;
        q.push(root);
        ans.push_back({root->val});
        while(!q.empty()){
            int n = q.size();
            vector<int>ans1;
            for(int i = 0; i < n; i++){
                Node *root = q.front();
                q.pop();
                if(root->children.size() == 0){
                    continue;
                }
                else{
                    for(int j = 0; j < root->children.size(); j++){
                        ans1.push_back(root->children[j]->val);
                        q.push(root->children[j]);
                    }
                }
            }
            if(ans1.size() == 0){
                continue;
            }
            else{
                ans.push_back(ans1);    
            }
            
        }
        return ans;
    }
};