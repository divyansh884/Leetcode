/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp=headA;
        ListNode *temp1=headB;
        while(temp!=NULL){
            if(temp==temp1)
            return temp;
            else
            temp1=temp1->next;
            if(temp1==NULL){
                temp1=headB;
                temp=temp->next;
            }
        }
        return NULL;
    }
};