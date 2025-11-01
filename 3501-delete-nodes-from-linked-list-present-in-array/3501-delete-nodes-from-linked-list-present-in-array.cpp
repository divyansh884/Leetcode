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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if (!head)
            return NULL;
        map<int, bool> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = true;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr != NULL) {
            if (mp.find(curr->val)!=mp.end()){
                if(curr!=head){
                    prev->next=curr->next;
                    curr->next=NULL;
                    curr=prev->next;
                }
                else{
                    ListNode* temp=curr->next;
                    curr->next=NULL;
                    curr=temp;
                    head=temp;
                }
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};