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
    void reorderList(ListNode* &head) {
        vector<int> ans;
        ListNode* temp=head;
        while(temp!=NULL){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        int s=0,e=ans.size()-1,i=0;
        while(s<=e){
            if(i%2==0){
            temp->val=ans[s];
            s++;
            }
            else{
                temp->val=ans[e];
                e--;
            }
            i++;
            temp=temp->next;
        }
    }
};