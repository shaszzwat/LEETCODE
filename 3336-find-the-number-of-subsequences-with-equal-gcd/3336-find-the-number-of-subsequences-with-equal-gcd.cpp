class Solution {
public:
    int mod=1000000007;
    int dp[201][201][201];
    int solve(int i, int gcd1,int gcd2,vector<int>& nums){
        if(i==nums.size()){
            if((gcd1==gcd2) && (gcd1!=0 && gcd2!=0)){
                return 1;
            }
            return 0;
        }
        if(dp[i][gcd1][gcd2]!=-1){
            return dp[i][gcd1][gcd2];
        }

        int skip=solve(i+1,gcd1,gcd2,nums);
        int seq1=solve(i+1,__gcd(gcd1,nums[i]),gcd2,nums);
        int seq2=solve(i+1,gcd1,__gcd(gcd2,nums[i]),nums);

        return dp[i][gcd1][gcd2]=(0LL+skip+seq1+seq2)%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,nums);
        
    }
};