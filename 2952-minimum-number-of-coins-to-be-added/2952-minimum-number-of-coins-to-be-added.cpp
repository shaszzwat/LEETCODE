class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(),coins.end());
        int cnt=0;
        int i=0;
        long long maxr=0;
        while(maxr<target){
            if(i<coins.size() && coins[i]<=maxr+1){
                maxr+=coins[i];
                i++;
                
            }
            else{
                cnt++;
                
                maxr+=maxr+1;
            }
        }
        return cnt;
        
    
        
    }
};