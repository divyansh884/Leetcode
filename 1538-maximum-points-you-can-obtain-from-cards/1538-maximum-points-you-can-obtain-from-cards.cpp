class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans=INT_MIN,sum=0,diff=0;
        for(int i=0;i<cardPoints.size();i++){
            sum+=cardPoints[i];
        }
        for(int i=0;i<cardPoints.size()-k;i++){
            diff+=cardPoints[i];
        }
        int i=0,j=cardPoints.size()-k;
       
         ans= max(ans,sum-diff);
        while(j<cardPoints.size()){
            diff+=cardPoints[j];
             diff-=cardPoints[i];
             j++;
             i++;
             ans= max(ans,sum-diff);
        }
        ans= max(ans,sum-diff);
        return ans;
    }
};