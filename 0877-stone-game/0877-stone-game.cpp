class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,vector<int>& piles){
        if(i>j){
            return 0;
        }
        if(i==j){
            return piles[i];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }


        int takei=piles[i]+min(solve(i+2,j,piles),solve(i+1,j-1,piles));
        int takej=piles[j]+min(solve(i,j-2,piles),solve(i+1,j-1,piles));

        return dp[i][j]= max(takei,takej);
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int n=piles.size();
        int sum=accumulate(piles.begin(),piles.end(),0);
        return solve(0,n-1,piles)>sum/2;
        
    }
};