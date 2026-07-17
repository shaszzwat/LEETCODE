class Solution {
public:
    int dp[501];
    int solve(int idx,int k,vector<int>& arr){
        if(idx>=arr.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int res=0;
        int currmax=0;
        for(int j=idx;j<arr.size() && j-idx+1<=k;j++){
            currmax=max(currmax,arr[j]);
            res=max(res,((j-idx+1)*currmax+solve(j+1,k,arr)));
        }
        return dp[idx]=res;

    

    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,k,arr);
        
    }
};