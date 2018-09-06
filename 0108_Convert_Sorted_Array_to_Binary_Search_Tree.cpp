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
    
    TreeNode* build(vector<int>& nums, int l, int r) {
        if(r == l) return nullptr;
        int m = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        root -> left = build(nums, l, m);
        root -> right = build(nums, m + 1, r);
        return root;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }
};