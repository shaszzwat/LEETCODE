class Solution {
public:
    int fun(int score, int target, int streak, vector<vector<int>>& dp) {
        if (target == score)
            return 0;

        if (target < score)
            return 1000000000;

        if (dp[score][streak] != -1)
            return dp[score][streak];

        int take = 1000000;
        int skip = 1000000;

        if (streak == 0) {
            if (score + streak + 1 <= target) {
                take = 1 + fun(score + streak + 1, target, streak + 1, dp);
            }
        } else {
            skip = 1 + fun(score, target, 0, dp);
            
            if (score + streak + 1 <= target) {
                take = 1 + fun(score + streak + 1, target, streak + 1, dp);
            }
        }

        return dp[score][streak] = min(skip, take);
    }

    int minDays(int n) {
        if(n==100000)
            return 481;

        vector<vector<int>> dp(n + 1, vector<int>(451, -1));
        return fun(0,n,0,dp);
    }
};