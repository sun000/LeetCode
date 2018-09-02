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
    ListNode* swapPairs(ListNode* head) {
        ListNode* a = nullptr, *b = nullptr, *c = nullptr, *d;
        if(head) b = head;
        if(head && head -> next) c = head -> next;
        if(!b || !c) return head;
        d = c -> next;
        head = c;
        for(;b && c ; ) {
            if(a) a -> next = c;
            c -> next = b;
            b -> next = d;
            a = b, b = d;
            if(d) c = d -> next;
            if(c) d = c -> next;
        }
        return head;
    }
};