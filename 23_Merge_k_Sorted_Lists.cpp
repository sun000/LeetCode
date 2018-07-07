/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution { //其实这里可以用一个队列维护在O(n)的时间复杂度下做出来，这里偷懒了下，套用了起那一题的代码   
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1 -> val > l2 -> val)
            swap(l1, l2);
        for(ListNode* p1 = l1, *p2 = l2; p1 && p2; ) {
            if(p1 -> next) {
                if(p1 -> next -> val <= p2 -> val)
                    p1 = p1 -> next;
                else {
                    ListNode * tmp1 = p1 -> next, *tmp2 = p2 -> next;
                    p1 -> next = p2;
                    p2 -> next = tmp1;
                    p1 = p1 -> next;
                    p2 = tmp2;
                }
            } else {
                p1 -> next = p2;
                break;
            }
        }
        return l1;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size()) return NULL;
        ListNode* ret = lists[0];
        for(int i = 1; i < lists.size(); i++) 
            ret = mergeTwoLists(ret, lists[i]);
        return ret;
    }
};