class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long curr=0;
        vector<long long>ans;
        for(int i=0;i<nums.size();i++){
            curr=max(curr,(long long)nums[i]);
            ans.push_back(__gcd(curr,(long long)nums[i]));


        }
        long long sum=0;
        int n=ans.size();
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size()/2;i++){
            if(i==n-i-1){
                continue;
            }
            sum+=__gcd(ans[i],ans[n-i-1]);
            
        }
        return sum;
       


        
    }
};