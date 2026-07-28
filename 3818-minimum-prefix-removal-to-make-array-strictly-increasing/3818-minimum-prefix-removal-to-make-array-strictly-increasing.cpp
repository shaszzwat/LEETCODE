class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {

        int n=nums.size();
        for(int i=n-1;i>=1;i--){
            if(nums[i]>nums[i-1]){
                continue;
            }
            else{
                return i;
            }
        }
        return 0;
        
    }
};