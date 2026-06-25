class Solution {
public:
    unordered_map<string,int>mpp;
    int n;
    int dp[301];
    bool solve(int idx,string &s){
        if(idx==n){
            return true;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }

        if(mpp.find(s)!=mpp.end()){
            return dp[idx]=true;
        }

        for(int i=1;i<s.size();i++){
            string temp=s.substr(idx,i);
            if(mpp.find(temp)!=mpp.end() && solve(idx+i,s)){
                return dp[idx]=true;
            }
        }
        return dp[idx]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        memset(dp,-1,sizeof(dp));
        for(auto it:wordDict){
            mpp[it]++;
        }
        return solve(0,s);
        
    }
};