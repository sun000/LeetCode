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
    int idx = 0;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int l, int r) {
        if(idx == preorder.size() || r == l) return nullptr;
        int m;
        for(m = l; m < r && inorder[m] != preorder[idx]; m++);
        TreeNode* now = new TreeNode(preorder[idx++]);
        now -> left = build(preorder, inorder, l, m);
        now -> right = build(preorder, inorder, m + 1, r);
        return now;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, inorder.size());
    }
};