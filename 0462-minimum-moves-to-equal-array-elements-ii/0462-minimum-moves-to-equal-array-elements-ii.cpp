class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<long long> pre;
        pre.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++) {
            pre.push_back(pre.back() + nums[i]);
        }

        long long mini = LLONG_MAX;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            long long sum = 0;

            if(i > 0) {
                sum += 1LL * i * nums[i] - pre[i-1];
            }

            if(i < n-1) {
                sum += (pre[n-1] - pre[i]) -
                       (1LL * (n-i-1) * nums[i]);
            }

            mini = min(mini, sum);
        }

        return (int)mini;
    }
};