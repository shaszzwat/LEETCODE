class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int l=0;
        int r=0;
        long long count=0;
        while(r<nums.size()){
            if(nums[r]!=0){
                r++;
                
            }
            else{
                while(r<nums.size() && nums[r]==0){
                    count+=r-l+1;
                    r++;
                }
            }
            l=r;
        }
        return count;
        
    }
};