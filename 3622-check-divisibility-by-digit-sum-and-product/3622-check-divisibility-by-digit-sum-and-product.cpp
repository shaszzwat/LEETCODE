class Solution {
public:
    bool checkDivisibility(int n) {
        int org=n;

        long long prod=1;
        long long sum=0;
        while(n>0){
            prod=prod*(n%10);
            sum+=n%10;
            n=n/10;
        }
        return org%(prod+sum)==0;
        
    }
};