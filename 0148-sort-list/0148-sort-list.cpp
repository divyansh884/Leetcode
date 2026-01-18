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
        if(head==NULL || head->next==NULL)
        return head;
        vector<int> nums;
        ListNode*temp=head;
        while(temp){
            nums.push_back(temp->val);
            temp=temp->next;
        }
        ListNode* ans=new ListNode(0);
        temp=ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            ListNode* tp= new ListNode(nums[i]);
            temp->next=tp;
            temp=tp;
        }
        return ans->next;
    }
};