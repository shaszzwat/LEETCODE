class Solution {
public:
    typedef long long ll;
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        vector<ll> arr(n, 0);

        unordered_map<int, ll> indexSum;
        unordered_map<int, ll> indexFreq;

       
        for (int i = 0; i < n; i++) {
            ll freq = indexFreq[nums[i]];
            ll sum = indexSum[nums[i]];

            arr[i] += freq * i - sum;

            indexFreq[nums[i]] += 1;
            indexSum[nums[i]] += i;
        }
        indexFreq.clear();
        indexSum.clear();

       
        for (int i = n - 1; i >= 0; i--) {
            ll freq = indexFreq[nums[i]];
            ll sum = indexSum[nums[i]];

            arr[i] += sum - freq * i;

            indexFreq[nums[i]] += 1;
            indexSum[nums[i]] += i;
        }
        return arr;
    }
};