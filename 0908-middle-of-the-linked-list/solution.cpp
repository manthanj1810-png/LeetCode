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
    int len(ListNode* head){
        if(head==NULL) return 0;
        return 1+len(head->next);
    }
    ListNode* middleNode(ListNode* head) {
       int n=len(head);
       ListNode *curr=head;
       for(int i=0;i<n/2;i++){
            curr=curr->next;
        }
        return curr; 
    }
};
