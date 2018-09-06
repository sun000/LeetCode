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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int l, int r) {
        if(idx < 0 || r == l) return nullptr;
        int m;
        for(m = l; m < r && inorder[m] != postorder[idx]; m++);
        TreeNode* now = new TreeNode(postorder[idx--]);
        now -> right = build(inorder, postorder, m + 1, r);
        now -> left = build(inorder, postorder, l, m);
        return now;
    }
public:
     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        idx = inorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size());
    }
};