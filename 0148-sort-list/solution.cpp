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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev=NULL, *slow=head,*fast=head;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        ListNode* left=sortList(head), *right=sortList(slow);
        return merge(left,right);
    }
    ListNode* merge(ListNode* left,ListNode* right){
        ListNode dummy(0);
        ListNode *tail= &dummy;
        while(left && right){
            if(left->val < right->val){
                tail->next=left;
                left=left->next;
            }else{
                tail->next=right;
                right=right->next;
            }
            tail=tail->next;
        }
        tail->next= left?left: right;
        return dummy.next;
    }
};
