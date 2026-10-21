#include <vector>

class Solution {
    int dir[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    double solve(int n, int r, int c, int k, std::vector<std::vector<std::vector<double>>>& dp) {
        if (r < 0 || r >= n || c < 0 || c >= n) {
            return 0.0;
        }

        if (k == 0) {
            return 1.0;
        }

        if (dp[r][c][k] >= 0.0) {
            return dp[r][c][k];
        }

        double prob = 0.0;
        for (int i = 0; i < 8; i++) {
            prob += solve(n, r + dir[i][0], c + dir[i][1], k - 1, dp) / 8.0;
        }

        return dp[r][c][k] = prob;
    }

public:
    double knightProbability(int n, int k, int row, int column) {
        std::vector<std::vector<std::vector<double>>> dp(
            n, std::vector<std::vector<double>>(n, std::vector<double>(k + 1, -1.0))
        );
        return solve(n, row, column, k, dp);
    }
};