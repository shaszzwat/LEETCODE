class Solution {
public:
    int n;
    int dp[101][101];

    int solve(int i, int m, vector<int>& pre) {
        if (i >= n)
            return 0;

        if (dp[i][m] != -1)
            return dp[i][m];

        int ans = 0;

        int remaining = pre[n] - pre[i];

        for (int x = 1; x <= 2 * m && i + x <= n; x++) {
            int opponent = solve(i + x, max(m, x), pre);

            ans = max(ans, remaining - opponent);
        }

        return dp[i][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        vector<int> pre(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + piles[i];
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, 1, pre);
    }
};