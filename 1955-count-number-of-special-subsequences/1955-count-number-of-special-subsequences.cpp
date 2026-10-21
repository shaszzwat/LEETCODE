class Solution {
public:
    int dp[100001][4];
    const int mod=1000000007;
    int solve(int i,int prev,vector<int>&nums){
        if(i>=nums.size()){
            if(prev==2){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int nottake=solve(i+1,prev,nums);
        int take=0;
        if(prev==-1){
            if(nums[i]==0){
                take+=(solve(i+1,nums[i],nums)%mod);
            }
        }
        if(prev==0){
            if(nums[i]==0 || nums[i]==1){
                take+=(solve(i+1,nums[i],nums)%mod);
            }
            
        }
        if(prev==1){
            if(nums[i]==1 || nums[i]==2){
                take+=(solve(i+1,nums[i],nums)%mod);
            }
        }

        if(prev==2 && nums[i]==2){
            take+=(solve(i+1,2,nums)%mod);
        }

        return dp[i][prev+1]=(take+nottake)%mod;
    }
    int countSpecialSubsequences(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));

        return solve(0,-1,nums);
        
    }
};