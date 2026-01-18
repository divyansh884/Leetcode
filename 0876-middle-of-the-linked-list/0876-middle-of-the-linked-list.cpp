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
        ListNode* temp= head;
        int i=0;
        while(temp!=NULL){
            temp= temp->next;
        i++;
        }
        return i;
    }
    ListNode* middleNode(ListNode* head) {
        int n= len(head)/2;
        int i=0;
        ListNode* temp= head;
        while(i!=n){
            temp= temp->next;
            i++;
        }
        return temp;
    }
};