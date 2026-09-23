class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int target = accumulate(nums.begin(), nums.end(), 0) - x;

        if(target < 0) return -1;

        int l = 0;
        int curr = 0;
        int mini = INT_MAX;

        for(int r = 0; r < n; r++) {
            curr += nums[r];

            while(curr > target && l <= r) {
                curr -= nums[l];
                l++;
            }

            if(curr == target) {
                mini = min(mini, n - (r-l+1));
            }
        }

        return mini == INT_MAX ? -1 : mini;
    }
};