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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(auto head:lists){
            if(head){
                pq.push({head->val,head});
            }
        }
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        while(!pq.empty()){
            tail->next=pq.top().second;
            if(pq.top().second->next!=nullptr){
                pq.push({pq.top().second->next->val,pq.top().second->next});
            }
            pq.pop();
            tail=tail->next;

        }
        tail->next=nullptr;
        return dummy->next;
        
        
    }
};