class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][m-1]){
                int left=0,right=m-1;
                while(left<=right){
                    int mid1=left+(right-left)/2;
                    if(matrix[mid][mid1]==target)
                    return true;
                    else if(matrix[mid][mid1]>target)
                    right=mid1-1;
                    else
                    left=mid1+1;
                }
                return false;
            }
            else if(target<matrix[mid][0])
            high=mid-1;
            else
            low=mid+1;
        }
        return false;      
    }
};