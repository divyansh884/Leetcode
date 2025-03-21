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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* ptr1 = l1 ;
        ListNode* ptr2 = l2 ;

        ListNode* head = new ListNode (-1) ;
        ListNode* tail = head ;

        int sum = 0 ;
        int carry = 0 ;
        while ( ptr1 != nullptr && ptr2 != nullptr )
        {
            sum = ptr1 -> val + ptr2 -> val + carry ;
            if( sum > 9 )
            {
                tail -> next = new ListNode ( sum % 10 ) ;
                tail = tail -> next ;
                carry = 1 ;
            }
            else 
            {
                tail -> next = new ListNode ( sum ) ;
                tail = tail -> next ;
                carry = 0 ;
            }
            ptr1 = ptr1 -> next ;
            ptr2 = ptr2 -> next ;
        }
        while ( ptr1 != nullptr )
        {
            sum = ptr1 -> val + carry ;
            if ( sum > 9 )
            {
                tail -> next = new ListNode ( sum % 10 ) ;
                tail = tail -> next ;
                carry = 1 ;
            }
            else
            {
                tail -> next = new ListNode ( sum ) ;
                tail = tail -> next ;
                carry = 0 ;
            }
            ptr1 = ptr1 -> next ;
        }
        while ( ptr2 != nullptr )
        {
            sum = ptr2 -> val + carry ;
            if ( sum > 9 )
            {
                tail -> next = new ListNode ( sum % 10 ) ;
                tail = tail -> next ;
                carry = 1 ;
            }
            else
            {
                tail -> next = new ListNode ( sum ) ;
                tail = tail -> next ;
                carry = 0 ;
            }
            ptr2 = ptr2 -> next ;
        }
        if ( carry == 1 )
            tail -> next = new ListNode ( 1 ) ;
        return head -> next ;
    }
};