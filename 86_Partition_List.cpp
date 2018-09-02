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
    ListNode* partition(ListNode* head, int x) {
        ListNode *h1 = nullptr, *h2 = nullptr, *t1 = nullptr, *t2 = nullptr;
        for(ListNode *p = head; p; p = p -> next) {
            if(p -> val < x) {
                if(!h1) h1 = t1 = p;
                else {
                    t1 -> next = p;
                    t1 = p;
                }
            }
            else {
                if(!h2) h2 = t2 = p;
                else {
                    t2 -> next = p;
                    t2 = p;
                }
            } 
        }
        if(t1) t1 -> next = h2;
        else h1 = h2;
        if(t2) t2 -> next = nullptr;
        return h1;
    }
};