class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
     int sum=0;
     for( auto it: apple)
     sum+=it;
     sort(capacity.begin(),capacity.end(),greater<int>());
     int index=0;
     for(auto it: capacity){
        if(sum>it){
            sum-=it;
            index++;
        }
        else{
            break;
        }
     }
     return index+1;
    }
};