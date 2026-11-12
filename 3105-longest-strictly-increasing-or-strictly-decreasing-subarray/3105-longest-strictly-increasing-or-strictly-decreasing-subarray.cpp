class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=1;
        int dec=1;
        int maxi=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                inc++;
                maxi=max(maxi,inc);
            }
            else{
                inc=1;
            }
        }
         for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                dec++;
                maxi=max(maxi,dec);
            }
            else{
                dec=1;
            }
        }
        return maxi;
        
    }
};