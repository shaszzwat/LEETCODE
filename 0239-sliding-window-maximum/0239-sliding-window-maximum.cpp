class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int> ms;

        for (int i = 0; i < k; i++) {
            ms.insert(nums[i]);
        }

        int l = 0;

        for (int r = k - 1; r < nums.size(); r++) {

            if (r >= k) {
                ms.insert(nums[r]);
            }

            ans.push_back(*ms.rbegin());

            auto it = ms.find(nums[l]);
            ms.erase(it);
            l++;
        }

        return ans;
    }
};