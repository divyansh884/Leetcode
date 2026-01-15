class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            while (temp != NULL) {
                pq.push(temp->val);
                temp = temp->next;
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (!pq.empty()) {
            ListNode* node = new ListNode(pq.top());
            pq.pop();
            curr->next = node;
            curr = node;
        }

        return dummy->next;
    }
};
