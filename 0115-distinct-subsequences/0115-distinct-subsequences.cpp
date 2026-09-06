class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,string &s,string &t){

        if(i==t.size()){
            return 1;
        }

        if(j==s.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        

        if(s[j]==t[i]){
            return dp[i][j]=solve(i+1,j+1,s,t) + solve(i,j+1,s,t);
        }
        else{
            return dp[i][j]=solve(i,j+1,s,t);
        }
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,t);
        
    }
};