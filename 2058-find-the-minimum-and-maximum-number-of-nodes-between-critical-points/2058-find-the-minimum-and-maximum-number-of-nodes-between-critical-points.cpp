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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* curr=head;
        ListNode* pre=NULL;
        ListNode* prepre=NULL;
        vector<int> ans;
        int ind=0;
        while(curr!=NULL){
            if(pre!=NULL && prepre!=NULL){
                if(pre->val>curr->val && pre->val>prepre->val)
                ans.push_back(ind-1);
                if(pre->val<curr->val && pre->val<prepre->val)
                ans.push_back(ind-1);
            }
            ind++;
            prepre=pre;
            pre=curr;
            curr=curr->next;
        }
        if(ans.size()<=1)
        return {-1,-1};
        int mini=INT_MAX;
        for(int i=0;i<ans.size()-1;i++){
            mini=min(mini,ans[i+1]-ans[i]);
        }
        int maxi=ans[ans.size()-1]-ans[0];
        return {mini,maxi};
    }
};