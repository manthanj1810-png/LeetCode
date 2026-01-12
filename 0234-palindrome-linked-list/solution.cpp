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
    ListNode* revlist(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* newhead = revlist(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        ListNode *slow = head, *fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // odd length → skip middle
        if(fast != NULL){
            slow = slow->next;
        }

        ListNode* second = revlist(slow);
        ListNode* first = head;

        while(second){
            if(first->val != second->val){
                return false;
            }
            first = first->next;
            second = second->next;
        }

        return true;
    }
};


