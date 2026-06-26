#define ll long long
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        ll ans=0;
        unordered_map<int,ll>mpp;
        mpp[0]=1;
        int currSum=0;
        ll valids=0;
        for(auto it:nums){
            if(it==target){
               valids+=mpp[currSum];
               currSum++;
            }
            else{
                currSum--;
                valids-=mpp[currSum];
            }
            ans+=valids;
            mpp[currSum]++;
        }
        return ans;
    }
};