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
    vector<int> element;
    int idx = 0;
    void getNum(TreeNode* root) {
        element.push_back(root -> val);
        if(root -> left) getNum(root -> left);
        if(root -> right) getNum(root -> right);
    }
    void recover(TreeNode* root) {
        if(root -> left) recover(root -> left);
        root -> val = element[idx++];
        if(root -> right) recover(root -> right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        getNum(root);
        sort(element.begin(), element.end());
        recover(root);
    }
};