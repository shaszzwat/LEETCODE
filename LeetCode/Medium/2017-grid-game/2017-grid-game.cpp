class Solution {
public:
    
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();

        long long firstrow=accumulate(grid[0].begin(),grid[0].end(),0LL);
        long long second=0;
        long long minsum=LONG_LONG_MAX;
        for(int i=0;i<n;i++){
            firstrow-=grid[0][i];
            long long robo2max=max(firstrow,second);
            minsum=min(minsum,robo2max);
            second+=grid[1][i];

        }
        return minsum;

    }
};