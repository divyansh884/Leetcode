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
int len(ListNode* head){
    ListNode* temp= head;
    int count=0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL|| head->next==NULL)
        return NULL;
        ListNode* curr= head;
        ListNode* prev=NULL;
        int i=0;
        int n=len(head)/2;
        while(i<n){
            prev=curr;
            curr=curr->next;
            i++;
        }
        ListNode* temp=curr->next;
        prev->next=temp;
        curr->next=NULL;
        return head;
    }
};