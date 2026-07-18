class Solution {
public:
    long long countGood(vector<int>& nums, int k) {

        int pairs=0;
        long long result=0;
        int l=0;
        int r=0;
        int n=nums.size();
        unordered_map<int,int>mpp;
        while(r<n){
            pairs+=mpp[nums[r]];
            mpp[nums[r]]++;
            while(pairs>=k){
                result+=n-r;
                mpp[nums[l]]--;
                pairs=pairs-mpp[nums[l]];
                l++;
            }
            r++;
        }
        return result;

        
    }
};