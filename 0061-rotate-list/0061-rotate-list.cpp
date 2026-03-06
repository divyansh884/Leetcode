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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
        if(head==NULL || head->next==NULL || k==0)
        return head;
        int cnt=0;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        int rotate=k%cnt;
        if(rotate==0)
        return head;
        int it=cnt-rotate;
        int cc=0;
        temp=head;
        ListNode* prev=NULL;
        while(cc!=it){
            prev=temp;
            temp=temp->next;
            cc++;
        }
        prev->next=NULL;
        ListNode* head1=temp;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=head;
        return head1;
    }
};