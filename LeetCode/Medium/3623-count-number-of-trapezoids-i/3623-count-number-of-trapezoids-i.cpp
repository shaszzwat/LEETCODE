class Solution {
public:
    const int mod = 1000000007;

    long long choose(long long n) {
        return n * (n - 1) / 2;
    }

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < points.size(); i++) {
            mpp[points[i][1]]++;
        }

        long long ans = 0;
        long long sum = 0;

        for (auto it : mpp) {
            if (it.second >= 2) {
                long long ways = choose(it.second);

                ans = (ans + (ways * sum) % mod) % mod;
                sum = (sum + ways) % mod;
            }
        }

        return (int)ans;
    }
};