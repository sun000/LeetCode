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
        ListNode *h = nullptr, *tail = nullptr, *pre = nullptr;
        for(ListNode* p = head; p != nullptr; ) {
            if(tail && p -> val == tail -> val) {
                while(p && p -> val == tail -> val)
                    p = p -> next;
                tail = pre;
                if(tail) tail -> next = nullptr;
                if(!tail) h = nullptr;
            } else {
                if(!h || !tail) h = tail = p;
                else {
                    tail -> next = p;
                    pre = tail;
                    tail = p;
                }
                p = p -> next;
            }
        }
        return h;
    }
};