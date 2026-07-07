class Solution {
public:
    const int mod=1000000007;
    int dp[5001][10];
    vector<vector<int>>adj={{4,6},{6,8},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4}};
    int solve(int n,int cell){
        if(n==0)return 1;
        if(dp[n][cell]!=-1){
            return dp[n][cell];
        }
        int ans=0;
        for(auto it:adj[cell]){
            ans=(ans+solve(n-1,it))%mod;
        }
        return dp[n][cell]=ans%mod;
    }
    int knightDialer(int n) {
        memset(dp,-1,sizeof(dp));
        int cnt=0;
        for(int i=0;i<=9;i++){
            cnt=(cnt+solve(n-1,i))%mod;

        }
        return cnt%mod;


        
    }
};