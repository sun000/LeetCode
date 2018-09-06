/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(!root) return v;
        
        queue<TreeNode*> q;
        q.push(root);
        int s = 1;
        while(!q.empty()) {
            vector<int> tmp;
            for(int i = 0; i < s; i++) {
                TreeNode* f = q.front();
                tmp.push_back(f -> val);
                q.pop();
                if(f -> left) q.push(f -> left);
                if(f -> right) q.push(f -> right);
            }
            s = q.size();
            v.push_back(tmp);
        }
        return v;
    }
};