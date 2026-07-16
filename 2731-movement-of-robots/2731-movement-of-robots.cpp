class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        const long long MOD = 1e9 + 7;

        vector<long long> pos(nums.begin(), nums.end());

        for (int i = 0; i < pos.size(); i++) {
            if (s[i] == 'L')
                pos[i] -= d;
            else
                pos[i] += d;
        }

        sort(pos.begin(), pos.end());

        vector<long long> pre(pos.size(), 0);
        pre[0] = pos[0];

        for (int i = 1; i < pos.size(); i++) {
            pre[i] = pre[i - 1] + pos[i];
        }

        long long sum = 0;

        for (int i = 1; i < pos.size(); i++) {
            long long cont = 1LL * pos[i] * i - pre[i - 1];
            sum = (sum + cont) % MOD;
        }

        return (sum + MOD) % MOD;
    }
};