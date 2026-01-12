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
    int lenl(ListNode *headA){
        if(headA==NULL) return 0;
        return 1+lenl(headA->next);
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n=lenl(headA),m=lenl(headB),x=max(n,m)-min(n,m);
        ListNode *slow= (n>m) ? headB:headA,*fast=(n>m) ? headA:headB;
        for(int i=0;i<max(n,m)-min(n,m);i++){
            fast=fast->next;
        }
        while(fast)
        {   if(slow==fast) return slow;
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    
    }
};
