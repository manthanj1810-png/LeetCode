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
        if(head==NULL) return 0;
        return 1+lenl(head->next);
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int t=lenl(head);
        if(t==1) return NULL;
        if(t==n){
            ListNode* curr=head;
            head=head->next;
            delete curr;
            return head;
        }
        ListNode* curr=head,*temp=curr;
        for(int i=0;i<t-n;i++){
            temp=curr;
            curr=curr->next;
        }
        temp->next=curr->next;
        delete curr;
        curr=nullptr;
        return head;
        
    }
};
