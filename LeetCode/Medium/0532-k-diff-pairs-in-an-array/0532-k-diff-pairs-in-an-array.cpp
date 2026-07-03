class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        

        unordered_map<int, int> mpp;
        set<pair<int, int>> st;

        for (int i = 0; i < nums.size(); i++) {
            int target1 = nums[i] + k;
            int target2 = nums[i] - k;

            if (mpp.find(target1) != mpp.end()) {
                st.insert({min(nums[i], target1), max(nums[i], target1)});
            }

            if (mpp.find(target2) != mpp.end()) {
                st.insert({min(nums[i], target2), max(nums[i], target2)});
            }

            mpp[nums[i]]++;
        }

        return st.size();
    }
};