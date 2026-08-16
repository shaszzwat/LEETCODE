class Solution {
public:
    int mod = 1000000007;

    int rev(int x) {
        int ans = 0;
        while (x > 0) {
            ans = ans * 10 + x % 10;
            x = x / 10;
        }
        return ans;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> mpp;
        long long pair = 0;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i] - rev(nums[i]);

            if (mpp.find(x) != mpp.end()) {
                pair = (pair + mpp[x]) % mod;
            }

            mpp[x] = (mpp[x] + 1) % mod;
        }

        return pair;
    }
};