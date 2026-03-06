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
        int cnt = 0;
        ListNode* temp = head;
        ListNode* oddhead = new ListNode(-1);
        ListNode* evenhead = new ListNode(-1);
        ListNode *oddtail = oddhead;
        ListNode* eventail = evenhead;
        while (temp) {
            if (cnt % 2 == 0) {
                oddtail->next = temp;
                oddtail = temp;
                // oddtail->next = NULL;
            } else {
                eventail->next = temp;
                eventail = temp;
                // eventail->next = NULL;
            }
            temp = temp -> next;
            cnt++;
        }
        eventail->next=NULL;
        oddtail->next = evenhead->next;
        return oddhead->next;
    }
};