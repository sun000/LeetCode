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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        queue<TreeNode*> q;
        int ans = 1;
        q.push(root);
        int s = 1;
        while(!q.empty()) {
            for(int i = 0; i < s; i++) {
                TreeNode* f = q.front();
                q.pop();
                if(!f -> left && !f -> right) return ans;
                
                if(f -> left) q.push(f -> left);
                if(f -> right) q.push(f -> right);
            }
            s = q.size();
            ans++;
        }
        return ans;
    }
};