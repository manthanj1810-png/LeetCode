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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *curr=head,*temp=curr->next,*pre=nullptr;
        int n=0;
        while(curr->next){
            curr->next=pre;
            pre=curr;
            curr=temp;
            temp=temp->next;
        }
        curr->next=pre;
        return curr;
    }
};
