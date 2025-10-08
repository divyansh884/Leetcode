class Solution {
public:
int f(int low, int high,vector<int> &arr,long long lt){
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>=lt){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(int i=0;i<n;i++){
            long long lt=(success+spells[i]-1)/spells[i];
            int re= f(0,m-1, potions,lt);
            if(re!=-1){
            ans.push_back(m-re);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};