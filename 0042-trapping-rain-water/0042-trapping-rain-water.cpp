class Solution {
public:
vector<int> prefixmax(vector<int>& height){
    int ans=height[0];
    vector<int> re(height.size());
    for(int i=0;i<height.size();i++){
        ans=max(ans,height[i]);
        re[i]=ans;
    }
    return re;
}
vector<int> suffixmax(vector<int>& height){
    int n=height.size();
    int ans=height[n-1];
    vector<int> re(n);
    for(int i=n-1;i>=0;i--){
        ans=max(ans,height[i]);
        re[i]=ans;
    }
    return re;
}
    int trap(vector<int>& height) {
        int total=0;
        vector<int> pref=prefixmax(height);
        vector<int> suff=suffixmax(height);
        for(int i=0;i<height.size();i++){
            if(height[i]<pref[i]&& height[i]<suff[i]){
                total+=min(pref[i],suff[i])-height[i];
            }
        }
        return total;
    }
};