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
    bool dfs(TreeNode* l, TreeNode* r) {
        if(l -> val != r-> val) return false;
        bool flag = true;
        if(l -> left && r -> right) 
            flag &= dfs(l -> left, r -> right);
        if(flag && l -> right && r -> left)
            flag &= dfs(l -> right, r -> left);
        
        if((l -> left && !(r -> right)) || ((!l -> left) && r -> right)
        || (l -> right && !(r -> left)) || ((!l -> right) && r -> left))
            flag = false;
        return flag;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        else return dfs(root, root);
    }
};