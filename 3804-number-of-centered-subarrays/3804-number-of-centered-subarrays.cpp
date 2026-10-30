class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();

        int result = 0;
        for (int i = 0; i < n; ++i) {
            int subsum = 0;
            unordered_set<int> subnums;
            for (int j = i; j < n; ++j) {
                subsum += nums[j];
                subnums.insert(nums[j]);
                result += (subnums.find(subsum) != subnums.end());
            }
        }

        return result;
    }
};