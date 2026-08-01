class Solution {
public:
    int dp[21][21];
    int solve(int i,int j,vector<int>& nums){
        if(i>j){
            return 0;
        }
        if(i==j){
            return nums[i];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }


        int takei=nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int takej=nums[j]+min(solve(i,j-2,nums),solve(i+1,j-1,nums));

        return dp[i][j]= max(takei,takej);
    }
    bool predictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int sum=0;
        int n=nums.size();
        for(auto it:nums){
            sum+=it;
        }
        
        int one=solve(0,n-1,nums);
        return sum-one<=one;
        
    }
};