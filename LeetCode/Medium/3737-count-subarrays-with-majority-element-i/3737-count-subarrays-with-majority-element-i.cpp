class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        int count=0;

        for(int i=0;i<n;i++){
            mpp.clear();
            for(int j=i;j<n;j++){
                mpp[nums[j]]++;
                if(mpp[target]>(j-i+1)/2){
                    count++;
                }
            }
        }
        return count;
    }
};