class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) 
            return head;

        ListNode* ans = new ListNode(-1);
        ListNode* tempa = ans;
        
        ListNode* evens = new ListNode(-1);
        ListNode* tempe = evens;

        ListNode* temp = head;
        
        while (temp != NULL) {
            tempa->next = temp;
            tempa = tempa->next;
            
            if (temp->next != NULL) {
                tempe->next = temp->next;
                tempe = tempe->next;
            }
            
            if (temp->next == NULL) 
                break;
                
            temp = temp->next->next;
        }
        
        tempe->next = NULL;
        
        temp = evens->next;
        while (temp != NULL) {
            tempa->next = temp;
            tempa = tempa->next;
            temp = temp->next;
        }
        
        tempa->next = NULL;
        
        ListNode* result = ans->next;
        delete ans;
        delete evens;
        
        return result;
    }
};