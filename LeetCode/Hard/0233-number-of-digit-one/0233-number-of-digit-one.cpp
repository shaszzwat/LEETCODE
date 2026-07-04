class Solution {
public:
    int dp[10][2][11];
    int solve(string &num,int idx,bool tight,int count){
        if(idx==num.size()){
            return count;
        }

        if(dp[idx][tight][count]!=-1){
            return dp[idx][tight][count];
        }
        int lb=0;
        int ub=0;
        if(tight){
            ub=num[idx]-'0';
        }
        else{
            ub=9;
        }

        

        int ans=0;
        for(int i=lb;i<=ub;i++){
            ans+=solve(num,idx+1,(tight && i==ub),(i==1)? count+1 : count);




        }
        return dp[idx][tight][count]=ans;
    }
    
    int countDigitOne(int n) {
        if(n==0){
            return 0;
        }
        string num=to_string(n);
        memset(dp,-1,sizeof(dp));

        return solve(num,0,1,0);
        
    }
};