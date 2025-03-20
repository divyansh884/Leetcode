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
        vector<int> n;
        if(head==NULL||head->next==NULL)
        return head;
        ListNode* temp= head;
        while(temp!=NULL){
            int m= temp->val;
            n.push_back(m);
            temp=temp->next;
        }
        sort(n.begin(),n.end());
        ListNode* ans= head;
        for(long long int i=0;i<n.size();i++){
            ans->val=n[i];
            ans=ans->next;
        }
        return head;
    }
};