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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == nullptr) return head;
        int cnt = 1;
        ListNode* tail = head, *p = head;
        for(;tail -> next; tail = tail -> next) cnt++;
        k %= cnt;
        if(k == 0) return head;
        k = cnt - k;
        // printf("cnt = %d k = %d\n", cnt, k);
        for(int i = 1; i < k; i++)
            p = p -> next;
        ListNode* tmp = head;
        head = p -> next;
        p -> next = nullptr;
        tail -> next = tmp;
        return head;
    }
};