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
    void mFatten(TreeNode* head, TreeNode** tail) {
        if(!head -> left && !head -> right) {
            *tail = head;
            return;
        }
        
        TreeNode* leftTail = head -> left, *rightTail = head -> right;
        
        if(head -> left) mFatten(head -> left, &leftTail);
        if(head -> right) mFatten(head -> right, &rightTail);
        
        if(head -> left) {
            leftTail -> right = head -> right;
            head -> right = head -> left;
            head -> left = nullptr;
        }
        if(!rightTail) *tail = leftTail;
        else *tail = rightTail;
        
        if((*tail) != nullptr) 
            (*tail) -> left = (*tail) -> right = nullptr;
    }
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* tail;
        mFatten(root, &tail);
    }
};