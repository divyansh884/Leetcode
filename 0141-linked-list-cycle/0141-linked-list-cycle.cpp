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
    bool hasCycle(ListNode *head) {
        if(!head)
        return false;
        ListNode* fwdptr=head; 
        ListNode* backptr=head;
        while(fwdptr->next!=NULL){
            fwdptr=fwdptr->next->next;
            if(fwdptr==NULL)
            return false;
            if(fwdptr==backptr)
            return true;
            backptr=backptr->next;
        }
        return false;
    }
};