class Solution {
public:
    int dp[2002][1001];
    
    int solve(vector<vector<int>>& pairs,int last,int i){
        if(i==pairs.size()){
            return 0;
        }
        if(dp[last+1001][i]!=-1){
            return dp[last+1001][i];
        }
        int skip=solve(pairs,last,i+1);
        int take=INT_MIN;
        if(last==-1001 || last<pairs[i][0]){
            take=1+solve(pairs,pairs[i][1],i+1);
        }
        return dp[last+1001][i]=max(skip,take);

    }
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp,-1,sizeof(dp));
        sort(pairs.begin(),pairs.end());

        return solve(pairs,-1001,0);
        
    }
};