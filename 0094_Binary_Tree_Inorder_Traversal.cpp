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
    vector<int> ret;
    void dfs(TreeNode* p) {
        if(p -> left) dfs(p -> left);
        ret.push_back(p -> val);
        if(p -> right) dfs(p -> right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root) dfs(root);
        return ret;
    }
};