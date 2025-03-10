class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n= blocks.size();
        int countb=0;
        int countw=0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W')
            countw++;
            else
            countb++;
        }
        int ans= countw;
        int i=0,j=k;
        cout<<countb;
        while(j<n){
            if(blocks[j]=='W' && blocks[i]=='B'){
                countb--;
                countw++;
            }
            else if(blocks[j]=='B' && blocks[i]=='W'){
                countb++;
                countw--;
            }
            j++;
            i++;
            ans= min(countw,ans);
        }
        return ans;
    }
};