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
    int length(ListNode* head) {
        ListNode* temp = head;
        int count = 1;
        while (temp->next != NULL) {
            temp = temp->next;
            count++;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int start = (length(head) - n) + 1;
        ListNode* curr =new ListNode(0, head);;
        ListNode* prev= NULL;
         if (start == 1) {
            head=head->next;
            return head;
         }
        int i = 1;
        while (i <= start) {
            prev = curr;
            curr = curr->next;
            i++;
        }
        prev->next=curr->next;
        curr->next = NULL;
        return head;
    }
};