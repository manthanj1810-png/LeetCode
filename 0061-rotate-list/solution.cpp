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
    int lenl(ListNode* head){
        if(!head) return 0;
        return 1+lenl(head->next);
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int n=lenl(head);
        ListNode* curr=head;
        if(n==0) return head;
        k=k%n;
        while(curr->next){
            curr=curr->next;
        }
        curr->next=head;
        curr=head;
        for(int i=0;i<n-k-1;i++){
            curr=curr->next;
        }
        head=curr->next;
        curr->next=NULL;
        return head;
    }
};
