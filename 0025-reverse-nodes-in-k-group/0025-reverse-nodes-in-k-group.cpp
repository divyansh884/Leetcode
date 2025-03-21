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
    int len(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            count++;
        }
        return count;
    }
    ListNode* ans(ListNode* pre,ListNode*cur,int k,int count){
        if(cur==NULL)
        return pre;
        if(len(cur)<k){
            ListNode*  temp=pre;
            while(temp->next!=NULL)
            temp= temp->next;
            temp->next= cur;
            return pre;
        }
        ListNode* curr = cur;
        ListNode* prev = NULL;
        int i = 0;
        count++;
        while (i < k) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            i++;
        }
        ListNode*  temp=pre;
            while(temp->next!=NULL)
            temp= temp->next;
            temp->next= prev;
        return ans(pre,curr,k,count);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        int i = 0;
        int count=1;
        while (i < k) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            i++;
        }
        return ans(prev,curr,k,count);
    }
};