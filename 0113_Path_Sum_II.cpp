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
    vector<vector<int>> ret;
    vector<int> path;
    void solve(TreeNode* now, int sum, int target) {
        path.push_back(now -> val);
        sum += (now -> val);
        if(!now -> left && !now -> right && sum == target)
            ret.push_back(path);
        else {
            if(now -> left) solve(now -> left, sum, target);
            if(now -> right) solve(now -> right, sum, target);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return ret;
        solve(root, 0, sum);
        return ret;
    }
};