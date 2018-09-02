/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tail = head;
        for(ListNode *p = head; p; p = p -> next) {
            if(tail -> val != p -> val) {
                tail -> next = p;
                tail = p;
            }
        }
        if(tail) tail -> next = nullptr;
        return head;
    }
};