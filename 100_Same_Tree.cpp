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
    bool isSameNode(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(p && q) {
            if(p -> val != q -> val) return false;
            if(((p -> left && q -> left) || (!p -> left && !q -> left)) &&
               ((p -> right && q -> right) || (!p -> right && !q -> right)))
                return true;
            else return false;
        }
        else return false;
    }
    
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!isSameNode(p, q)) return false;
        bool flag = true;
        if(p -> left) flag &= isSameTree(p -> left, q -> left);
        if(p -> right) flag &= isSameTree(p -> right, q -> right);
        return flag;
    }
};