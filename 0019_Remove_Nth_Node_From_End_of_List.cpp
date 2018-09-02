/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int getSize(ListNode* head) {
        int cnt = 0;
        for(ListNode* p = head; p != NULL; p = p -> next, cnt++);
        return cnt;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int tmp = getSize(head) - n;
        ListNode* p;       
        if(!tmp) {
            p = head -> next;
            delete head;
            return p;
        }
        for(p = head; tmp > 1; p = p -> next, tmp--);
        ListNode* d = p -> next;
        p -> next = p -> next -> next;
        delete d;
        return head;
    }
};