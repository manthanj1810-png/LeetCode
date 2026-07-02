/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rev(ListNode* head,ListNode* end){
        if(head==end || head->next==end) return head;
        ListNode* nwh=rev(head->next,end);
        head->next->next=head;
        head->next=NULL;
        return nwh;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=0;
        ListNode* curr=head;
        while(curr){
            n++;
            curr=curr->next;
        }
        int cnt=n/k;
        ListNode* prev=NULL, *start=head;
        for(int i=0;i<cnt;i++){
            ListNode* temp=start;
            for(int j=0;j<k-1;j++){
                temp=temp->next;
            }
            ListNode* nwstart=temp->next;
            if(prev) prev->next=rev(start,nwstart);
            else head=rev(start,nwstart);
            prev=start;
            start=nwstart;
        }
        if(prev) prev->next=start;
        return head;
    }
};
