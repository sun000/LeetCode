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
    struct node {
        int minVal, maxVal;
        bool flag;
        node(int a, int b):minVal(a),maxVal(b){ flag = true; }
    };
    
    node dp(TreeNode* root) {
        node ret = node(root -> val, root -> val);
        if(root -> left) {
            node lnode = dp(root -> left);
            if(!lnode.flag || lnode.maxVal >= root -> val) {
                ret.flag = false;
                return ret;
            } 
            ret.minVal = min(lnode.minVal, root -> val);
        }
        if(root -> right) {
            node rnode = dp(root -> right);
             if(!rnode.flag || rnode.minVal <= root -> val) {
                ret.flag = false;
                return ret;
            }
            ret.maxVal = rnode.maxVal;
        }
        if(!root -> left && !root -> right) 
            ret.flag = true;
        return ret;
    }
    
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return dp(root).flag;
    }
};