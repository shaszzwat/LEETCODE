class Solution {
public:
    int dp[50001];
    int getidx(vector<vector<int>>&arr,int low,int val){
        int high=arr.size()-1;
        int ans=arr.size();
       
        while(low<=high){
             int mid=(low+high)/2;
             if(arr[mid][0]>=val){
                ans=mid;
                high=mid-1;

             }
             else{
                low=mid+1;
             }

        }
        return ans;
    }

    int solve(vector<vector<int>>&arr,int idx){
        if(idx>=arr.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int next=getidx(arr,idx+1,arr[idx][1]);
        int take=arr[idx][2]+solve(arr,next);
        int nottake=solve(arr,idx+1);
        return dp[idx]=max(take,nottake);
    }
    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>arr;
        for(int i=0;i<profit.size();i++){
            arr.push_back({start[i],end[i],profit[i]});
        }
        sort(arr.begin(),arr.end());
        return solve(arr,0);

        
    }
};