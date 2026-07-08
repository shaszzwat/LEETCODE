class Solution {
public:
    int n;
    int dp[8];
    int solve(vector<int>& nums,vector<bool>& visited,int op,unordered_map<vector<bool>,int>&mp){
        if(op==n+1){
            return 0;
        }
        if(mp.find(visited)!=mp.end()){
            return mp[visited];
        }
        
        int maxscore=0;
        for(int i=0;i<=n-2;i++){
            if(visited[i]){
                continue;
            }
           
            for(int j=i+1;j<n;j++){
                if(visited[j]){
                    continue;
                }
                visited[j]=1;
                visited[i]=1;
                int sum=op*__gcd(nums[i],nums[j]);
                int rems=solve(nums,visited,op+1,mp);
                maxscore=max(maxscore,sum+rems);
                visited[i]=0;
                visited[j]=0;
            }
        }

        return mp[visited]=maxscore;
    }
    int maxScore(vector<int>& nums) {
        n=nums.size();
        unordered_map<vector<bool>,int>mp;
        vector<bool>visited(n,0);
        return solve(nums,visited,1,mp);
        
    }
};