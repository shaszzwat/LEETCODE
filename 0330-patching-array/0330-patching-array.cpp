class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int cnt=0;
        int i=0;
        long long maxr=0;
        while(maxr<n){
            if(i<nums.size() && nums[i]<=maxr+1){
                maxr+=nums[i];
                i++;
                
            }
            else{
                cnt++;
                
                maxr+=maxr+1;
            }
        }
        return cnt;
        
    }
};