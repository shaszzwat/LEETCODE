class Solution {
public:
    int atmost(vector<int>& nums,int a){
        int count=0;
        int l=0;
        int r=0;
        unordered_map<int,int>mpp;
        while(r<nums.size()){
            mpp[nums[r]]++;
            while(mpp.size()>a){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            if(mpp.size()<=a){
                count+=r-l+1;
            }
            r++;


        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
        
    }
};