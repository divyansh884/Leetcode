class Solution {
public:
bool check(int n){
    vector<int> count(10,0);
    while(n!=0){
        count[n%10]++;
        n/=10;
    }
    for(int i=0;i<10;i++){
        if(count[i]>0 && count[i]!=i)
        return false;
    }
    return true;
}
    int nextBeautifulNumber(int n) {
        for(int i=n+1;i<=1224444;i++){
            if(check(i))
            return i;
        }
        return -1;
    }
};