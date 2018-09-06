/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
     TreeNode* build(vector<int>& nums, int l, int r) {
        if(r == l) return nullptr;
        int m = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        root -> left = build(nums, l, m);
        root -> right = build(nums, m + 1, r);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        for(ListNode* p = head; p; p = p -> next) 
            nums.push_back(p -> val);
        return build(nums, 0, nums.size());
    }
};