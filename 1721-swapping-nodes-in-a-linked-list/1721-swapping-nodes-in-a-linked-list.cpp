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
    ListNode* swapNodes(ListNode* head, int k) {

        int n=0;
        ListNode* temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        ListNode* one;
        ListNode* two;
        int cnt=0;
        int back=n-k+1;
        if(back==k){
            return head;
        }
        temp=head;
        while(temp){
            cnt++;
            if(cnt==k){
                one =temp;
            }
            if(cnt==back){
                two=temp;
            }
            temp=temp->next;
        }
        int value=one->val;
        one->val=two->val;
        two->val=value;
        return head;
    }
};