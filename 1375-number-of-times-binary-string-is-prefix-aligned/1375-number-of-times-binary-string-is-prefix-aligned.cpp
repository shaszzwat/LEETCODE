class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {

        int count=0;
        long long sum=0;

        for(int i=0;i<flips.size();i++){
            int n=i+1;

            sum+=flips[i];
            if(1LL*n*(n+1)/2==sum){
                count++;
            }
            
            
        }
        return count;


        
    }
};