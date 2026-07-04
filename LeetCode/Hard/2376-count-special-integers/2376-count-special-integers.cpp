class Solution {
public:
    map<tuple<int, bool, bool, vector<int>>, int> dp;
    int solve(string &num,int idx,bool tight,bool lz,vector<int>&visited){
        if(idx==num.size()){
            return !lz ? 1 :0;
        }
        auto state = make_tuple(idx, tight, lz, visited);
        if (dp.count(state)) {
            return dp[state];
        }

        int lb=0;
        int ub=(tight==1)? num[idx]-'0':9;
        int ans=0;
        for(int i=lb;i<=ub;i++){
            if(lz && i==0){
                ans+=solve(num,idx+1,0,1,visited);
                continue;

            }
            if(visited[i]!=0){
                continue;
            }
            visited[i]=1;

            ans+=solve(num,idx+1,(tight==1 && i==ub),0,visited);
            visited[i]=0;




        }
        return dp[state]=ans;
    }
    int countSpecialNumbers(int n) {
    
        string num=to_string(n);
        vector<int>visited(10,0);
        return solve(num,0,1,1,visited);
        
    }
};