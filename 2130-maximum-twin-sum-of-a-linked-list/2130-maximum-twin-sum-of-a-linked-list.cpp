class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> list;
        while(head!=NULL){
            list.push_back(head->val);
            head=head->next;
        }
        int n=list.size();
        int mxsum=0;
        for(int i=0;i<n/2;i++){
            mxsum=max(mxsum,list[i]+list[n-1-i]);
        }
        return mxsum;
    }
};
