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
    bool flag = true;
    int depth(TreeNode* root) {
        if(!flag || !root) return 0;
        int l, r;
        l = r = 1;
        if(root -> left) l += depth(root -> left);
        if(root -> right) r += depth(root -> right);
        if(l - r > 1 || r -l > 1) flag = false;
        return max(l, r);
    }
public:
    bool isBalanced(TreeNode* root) {
        depth(root);
        return flag;
    }
};