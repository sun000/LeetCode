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
        TreeLinkNode* head = root, *nextLevelHead = root -> left;
        while(nextLevelHead) {
            TreeLinkNode* pre = nullptr;
            for(TreeLinkNode* p = head; p; p = p -> next) {
                if(!pre) 
                    nextLevelHead = p -> left;
                if(p -> left) {
                    p -> left -> next = p -> right;
                    if(pre) 
                        pre -> right -> next = p -> left;     
                }
                pre = p;
            }
            head = nextLevelHead;
        }
    }
};