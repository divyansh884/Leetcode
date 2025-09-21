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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       if(!list1)
       return list2;
       if(!list2)
       return list1;
       ListNode* temp1=list1;
       ListNode* temp2=list2;
       ListNode* prev=NULL;
       while(temp1 && temp2){
        if(temp1->val>temp2->val){
                ListNode* temp=temp2->next;
                temp2->next=temp1;
                if(prev!=NULL){
                prev->next=temp2;
                }
                else{
                list1=temp2;
                }
                prev=temp2;
                temp2=temp;
        }
        else{
            prev=temp1;
            temp1=temp1->next;
        }
       }
       if(temp2!=NULL)
       prev->next=temp2;
       return list1;
    }
};