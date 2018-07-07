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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        ListNode* h = nullptr, *p = head;
        stack<ListNode*> s;
        
        for(;p; ) {
            s.push(p);
            if(s.size() == k) {
                p = s.top() -> next;
                if(h) {
                    h -> next = s.top();
                    h = h -> next;
                    s.pop();
                } else {
                    h = head = s.top();
                    s.pop();
                }
                for(int i = 1; i < k; i++) {
                    h -> next = s.top();
                    h = h -> next;
                    s.pop();
                }
                h -> next = p;
            }
            else p = p -> next;
        }
        return head;
    }
};