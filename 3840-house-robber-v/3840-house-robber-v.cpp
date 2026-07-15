class Solution {
public:
    long long dp[100005][2];

    long long solve(int idx, int prevRobbed, vector<int>& nums, vector<int>& colors) {
        if (idx == nums.size())
            return 0;

        if (dp[idx][prevRobbed] != -1)
            return dp[idx][prevRobbed];

        
        long long notTake = solve(idx + 1, 0, nums, colors);

        
        long long take = 0;

        if (!prevRobbed) {
            take = nums[idx] + solve(idx + 1, 1, nums, colors);
        } else {
            
            if (colors[idx] != colors[idx - 1]) {
                take = nums[idx] + solve(idx + 1, 1, nums, colors);
            }
        }

        return dp[idx][prevRobbed] = max(take, notTake);
    }

    long long rob(vector<int>& nums, vector<int>& colors) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, nums, colors);
    }
};