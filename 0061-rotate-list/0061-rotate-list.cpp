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
        int cnt=1;
        if(head==nullptr)
        return 1;
        ListNode* temp= head;
        while(temp->next!=nullptr){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int i = 0;
        k= k%len(head);
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;
        while (i < k) {
            ListNode* curr = head;
            ListNode* prev = nullptr;
            while (curr->next != nullptr) {
                prev = curr;
                curr = curr->next;
            }
            curr->next = head;
            prev->next = nullptr;
            head = curr;
            i++;
        }
        return head;
    }
};