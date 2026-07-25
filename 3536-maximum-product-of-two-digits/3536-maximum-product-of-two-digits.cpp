class Solution {
public:
    int maxProduct(int n) {
        int num1=INT_MIN,num2=INT_MIN;
        int temp=n;
        while(temp!=0){
            int t=temp%10;
            if(t>num1){
                num2=num1;
                num1=t;
            }
            else
            num2=max(num2,t);
            temp/=10;
        }
        return num1*num2;
    }
};