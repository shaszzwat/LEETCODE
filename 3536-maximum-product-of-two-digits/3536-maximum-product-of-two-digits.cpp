class Solution {
public:
    int maxProduct(int n) {
        vector<int>v(10,0);
        while(n>0){
            v[n%10]++;
            n=n/10;
        }
        int num1=-1;
        int num2=-1;
        for(int i=9;i>=0;i--){
            if(num1==-1 && num2==-1 && v[i]>=2){
                return i*i;
            }
            if(num1==-1 && v[i]>=1){
                num1=i;
                continue;
            }
            if(num2==-1 && v[i]>=1){
                num2=i;
                continue;
            }
        }
        return num1*num2;
        
    }
};