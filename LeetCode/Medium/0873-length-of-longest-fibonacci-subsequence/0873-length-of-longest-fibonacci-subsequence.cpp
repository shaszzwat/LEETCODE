class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,unordered_map<int,int>&mpp,vector<int>&arr){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int findi=arr[j]-arr[i];
        
        if(mpp.find(findi)!=mpp.end() && mpp[findi]<i){
            return solve(mpp[findi],i,mpp,arr)+1;


        }
        return 2;
    }
    
    int lenLongestFibSubseq(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        unordered_map<int,int>mpp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mpp[arr[i]]=i;
        }
        int count=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a=solve(i,j,mpp,arr);
                if(a>=3){
                    count=max(count,a);
                }
            }
        }
        return count;
        
    }
};