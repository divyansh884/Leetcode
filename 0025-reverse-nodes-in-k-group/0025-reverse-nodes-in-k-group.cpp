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
    ListNode* reverseKGroup(ListNode* head, int k) {
        map<ListNode*,ListNode*> mp;
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            mp[temp]=prev;
            prev=temp;
            temp=temp->next;
        }
        int cnt=0;
        temp=head;
        ListNode* st=head;
        while(temp!=NULL){
            if(cnt==0)
            st=temp;
            cnt++;
            if(cnt==k){
                int i=0;
                int j=k-1;
                ListNode* tt=temp;
                while(i<j){
                    swap(st->val,tt->val);
                    st=st->next;
                    tt=mp[tt];
                    i++;
                    j--;
                }
                cnt=0;
            }
            temp=temp->next;
        }
        return head;
    }
};