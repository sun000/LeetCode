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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result, *head, *list1, *list2;//result用来存结果
        list1 = l1;
        list2 = l2;//用list1,2接收参数
        //head的添加
        head = result = new ListNode(0);
        int cnt = 0;
        int x, x1, x2;
        while(list1 != NULL || list2 !=NULL){
            x1 = (list1 != NULL) ? (list1->val) : 0;
            x2 = (list2 != NULL) ? (list2->val) : 0;
            x = (x1 + x2 + cnt) % 10;
            cnt = (x1 + x2 + cnt)/10;
            result -> next = new ListNode(x);
            if(list1) list1 = list1->next;
            if(list2) list2 = list2->next;
            result = result->next;     
        }
        if(cnt)  result -> next = new ListNode(cnt);
        return head->next;  
    }
};