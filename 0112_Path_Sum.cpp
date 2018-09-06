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
    bool flag = false;
    void check(TreeNode* now, int sum, int target) {
        sum += (now -> val);
        if(flag || (!now -> left && !now -> right && sum == target))
            flag = true;
        else {
            if(now -> left) check(now -> left, sum, target);
            if(!flag && now -> right) check(now -> right, sum, target);
        }
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        check(root, 0, sum);
        return flag;
    }
};