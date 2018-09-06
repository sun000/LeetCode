/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        stack<TreeLinkNode*> s[2];
        s[0].push(root);
        while(!s[0].empty()) {
            TreeLinkNode* mNext = nullptr;
            while(!s[0].empty()) {
                TreeLinkNode* t = s[0].top();
                s[0].pop();
                t -> next = mNext;
                mNext = t;
                
                if(t -> right) s[1].push(t -> right);
                if(t -> left) s[1].push(t -> left);
            }
            while(!s[1].empty()) {
                s[0].push(s[1].top());
                s[1].pop();
            }
        }
    }
};