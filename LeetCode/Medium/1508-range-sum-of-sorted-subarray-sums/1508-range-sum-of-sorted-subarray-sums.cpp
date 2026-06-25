class Solution {
public:
    const int mod = 1e9 + 7;

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> sum;

        for (int i = 0; i < n; i++) {
            long long sumi = 0;
            for (int j = i; j < n; j++) {
                sumi += nums[j];
                sum.push_back(sumi); 
            }
        }

        sort(sum.begin(), sum.end());

        for (int i = 1; i < sum.size(); i++) {
            sum[i] += sum[i - 1];      
        }

        if (left == 1)
            return sum[right - 1] % mod;

        return (sum[right - 1] - sum[left - 2]) % mod;
    }
};