class Solution {
public:
    int minOperations(int n) {
        
        int ini=1;
        int count=0;
        for(int i=0;i<n/2;i++){
            count+=n-ini;
            ini=ini+2;


        }
        
        return count;
    }
};