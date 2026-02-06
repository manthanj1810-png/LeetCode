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
class compare{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       ListNode *ans=new ListNode();
       ListNode* curr=ans;
       priority_queue<ListNode*, vector<ListNode*>, compare> pq;
       for (auto list : lists) {
            if (list != NULL)
                pq.push(list);
        }
        while(!pq.empty()){
            ListNode *small=pq.top();
            curr->next=small;
            pq.pop();
            curr=curr->next;
            if(small->next!=NULL){
               pq.push(small->next); 
            }
        }
       return ans->next;
    }
};
