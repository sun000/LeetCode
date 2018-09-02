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
    TreeNode* TreeAddNum(TreeNode* root, int num) {
        if(!root) return nullptr;
        TreeNode* now = new TreeNode(root -> val + num);
        if(root -> left) now -> left = TreeAddNum(root -> left, num);
        if(root -> right) now -> right = TreeAddNum(root -> right, num);
        return now;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> allTree[100];
        if(n == 0) return allTree[0];
        
        allTree[0].push_back(nullptr);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                for(int i1 = 0; i1 < allTree[j - 1].size(); i1++) {
                    for(int i2 = 0; i2 < allTree[i - j].size(); i2++) {
                        TreeNode* now = new TreeNode(j);
                        now -> left = allTree[j - 1][i1];
                        now -> right = TreeAddNum(allTree[i - j][i2], j);
                        allTree[i].push_back(now);
                    }
                }
            }
        }
        return allTree[n];
    }
};