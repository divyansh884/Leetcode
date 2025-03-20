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
    ListNode* oddEvenList(ListNode* head) {
        int count=1;
        vector<int> odd;
        vector<int> even;
        ListNode* temp= head;
        while(temp!=NULL){
            if(count%2==0){
                even.push_back(temp->val);
            }
            else
            odd.push_back(temp->val);
            count++;
            temp=temp->next;
        }
        ListNode* ans= new ListNode(0);
        ListNode*temp1=ans;
        for(int i=0;i<odd.size();i++){
            ListNode* temp2= new ListNode(odd[i]);
            temp1->next=temp2;
            temp1=temp2;
        }
        for(int i=0;i<even.size();i++){
            ListNode* temp2= new ListNode(even[i]);
            temp1->next=temp2;
            temp1=temp2;
        }
        return ans->next;
    }
};