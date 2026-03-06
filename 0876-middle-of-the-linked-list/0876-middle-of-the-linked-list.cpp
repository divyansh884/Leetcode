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
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        int mid = (cnt + 1) / 2;
        temp = head;
        int cal = 0;
        while (cal != mid) {
            cal++;
            if (cal < mid)
                temp = temp->next;
        }
        if(cnt%2==0)
        temp=temp->next;
        return temp;
    }
};