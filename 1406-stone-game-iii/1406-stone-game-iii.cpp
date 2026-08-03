class Solution {
public:
    int dp[50001];

    int solve(int i, vector<int>& stoneValue) {
        if (i >= stoneValue.size()) {
            return 0;
        }
        if (dp[i] != INT_MIN) {
            return dp[i];
        }

        int one = stoneValue[i] - solve(i + 1, stoneValue);
        
        int two = (i + 1 < stoneValue.size()) 
                    ? stoneValue[i] + stoneValue[i + 1] - solve(i + 2, stoneValue) 
                    : INT_MIN;
                    
        int three = (i + 2 < stoneValue.size()) 
                      ? stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - solve(i + 3, stoneValue) 
                      : INT_MIN;

        return dp[i] = max(one, max(two, three));
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        fill(dp, dp + n + 1, INT_MIN);

        int a = solve(0, stoneValue);
        if (a > 0) return "Alice";
        if (a < 0) return "Bob";
        return "Tie";
    }
};