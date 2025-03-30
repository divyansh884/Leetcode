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
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<lists.size();i++){
            ListNode* temp=lists[i];
            while(temp!=NULL){
                pq.push(temp->val);
                temp=temp->next;
            }
        }
        ListNode* ans =new ListNode(-1);
        ListNode* temp =ans;
        while(!pq.empty()){
            temp->next= new ListNode(pq.top());
            temp=temp->next;
            pq.pop();
        }
        return ans->next;
    }
};