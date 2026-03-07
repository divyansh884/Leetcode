class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int tot=0,n=cardPoints.size();
        int sum=0;
        for(int i=0;i<n;i++){
            tot+=cardPoints[i];
        }
        for(int i=0;i<n-k;i++){
            sum+=cardPoints[i];
        }
        int i=0,j=n-k;
        int sub=sum;
        while(j<n){
            sum+=cardPoints[j];
            sum-=cardPoints[i];
            sub=min(sub,sum);
            j++;
            i++;
        }
        return tot-sub;
    }
};