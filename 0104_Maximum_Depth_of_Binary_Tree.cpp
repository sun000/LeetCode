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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int s = 1;
        int dpth = 0;
        while(!q.empty()) {
            for(int i = 0; i < s; i++) {
                TreeNode* f = q.front();
                q.pop();
                if(f -> left) q.push(f -> left);
                if(f -> right) q.push(f -> right);
            }
            s = q.size();
            dpth++;
        }
        return dpth;
    }
};