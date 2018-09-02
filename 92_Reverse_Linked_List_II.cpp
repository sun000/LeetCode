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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* h, *t, *l;
        m++, n++;
        ListNode* g = new ListNode(0);
        g -> next = head;
        head = g;

        n -= m;
        for(h = head; m > 2; m--) h = h -> next;
        l = h;
        h = t = h -> next;
        
        ListNode* p = h -> next;
        for( ; n; n--) {
            ListNode* tmp = p;
            p = p -> next;
            tmp -> next = h;
            h = tmp;
        }
        l -> next = h;
        t -> next = p;
        return head -> next;
    }
};